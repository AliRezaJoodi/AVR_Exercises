/**
 * @brief TM1638 LED driver.
 *
 * TM1638 uses a proprietary 2-wire protocol and is not I2C compatible.
 * Do not share TM1638 CLK/DIO lines with I2C SDA/SCL buses.
 *
 * TM1638 Hardware Mapping Notes:
 * - Segments SEG1 to SEG8 are connected to the 8-segment display (7 segments + decimal point).
 * - LEDs 1 to 8 are connected to SEG9.
 * - LEDs 9 to 16 are connected to both SEG9 and SEG10.
 * - Buttons 1 to 8 are connected to K3.
 * - Buttons 9 to 16 are connected to K2 and K3.
 * - Buttons 17 to 24 are connected to K1, K2, and K3.
 *
 * @author AliReza Joodi
 * @see https://github.com/AliRezaJoodi
 */

#ifndef TM1638_INCLUDED
#define TM1638_INCLUDED


#include <stdint.h>
#include <io.h>
#include <delay.h>

#include <utility_bit.h>

/**
 * @note Default hardware macros can be overridden by the user.
 */
#include "hardware.h"

#ifndef TM1638_HARDWARE
#define TM1638_HARDWARE
    #warning "TM1638_HARDWARE is not defined; default configuration will be used."
    #define TM1638_CLK_DDR         DDRC
    #define TM1638_CLK_PORT        PORTC
    #define TM1638_CLK_BIT         7

    #define TM1638_DIO_DDR         DDRC
    #define TM1638_DIO_PIN         PINC
    #define TM1638_DIO_PORT        PORTC
    #define TM1638_DIO_BIT         6
#endif

#ifndef TM1638_HARDWARE_EXTRA
#define TM1638_HARDWARE_EXTRA
    #define TM1638_STB1_DDR        DDRA
    #define TM1638_STB1_PORT       PORTA
    #define TM1638_STB1_BIT        7
#endif

/**
 * @brief Bit delay time in microseconds.
 *
 * This value defines the TM1638 clock timing.
 * One full clock period is equal to (TM1637_HALF_BIT_US * 2).
 *
 * @note Typical clock frequency is 500KHz
 * @note Maximum clock frequency is 1MHz
 */
#ifndef TM1638_BIT_US
#define TM1638_BIT_US            1
#endif

/**
 * @brief TM1638 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1638 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} TM1638_Pin_t;

/**
 * @brief TM1638 device handle.
 *
 * This structure holds STB pin that required
 * to control one TM1638 device instance.
 *
 * Example usage:
 * @code
 * TM1638_t tm1;
 * tm1.stb.ddr     = &TM1638_STB1_DDR;
 * tm1.stb.port    = &TM1638_STB1_PORT;
 * tm1.stb.index   =  TM1638_STB1_BIT;
 * @endcode
 */
typedef struct {
    TM1638_Pin_t stb;
} TM1638_t;

/**
 * @brief Initialize the TM1638 module.
 *
 * This function initializes the TM1638 interface by configuring the STB, CLK, and DIO pins
 * as outputs and setting them to their idle states. It also clears all display segments
 * and sets the display ON with maximum brightness.
 *
 * The initialization sequence ensures the module is ready for normal operation,
 * including LED control and key scanning.
 *
 * @param tm Pointer to TM1638 handle structure.
 *
 * @note STB, CLK, and DIO pins are set to high (idle) after configuration.
 * @note Display is turned ON with brightness level 7 after reset.
 */
void TM1638_Config(TM1638_t *tm);

/**
 * @brief Send a command byte to the TM1638 module.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param command Command byte to send.
 */
void TM1638_SendCommand(TM1638_t *tm, uint8_t command);

/**
 * @brief Set the TM1638 display ON/OFF and brightness.
 *
 * This function controls the TM1638 display according to the datasheet.
 * It sets the display ON or OFF and adjusts the pulse width to control brightness.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param onoff Display ON/OFF control:
 *          0: Display OFF
 *          1: Display ON
 * @param brightness Brightness level (0~7):
 *          0: Pulse width 1/16
 *          1: Pulse width 2/16
 *          2: Pulse width 4/16
 *          3: Pulse width 10/16
 *          4: Pulse width 11/16
 *          5: Pulse width 12/16
 *          6: Pulse width 13/16
 *          7: Pulse width 14/16
 *
 * @return Error flags (bitfield):
 *          Bit 0: onoff param was invalid and corrected
 *          Bit 1: brightness param was invalid and corrected
 */
uint8_t TM1638_SetDisplay(TM1638_t *tm, uint8_t onoff, uint8_t brightness);

/**
 * @brief Clear all segments on the TM1638 display.
 *
 * Resets all LEDs and display segments to 0.
 * Writes zeros to all 16 addresses using the module's command protocol.
 *
 * @param tm Pointer to TM1638 handle structure.
 */
void TM1638_ClearDisplay(TM1638_t *tm);

/**
 * @brief Write a single byte of segment data to a fixed digit address.
 *
 * This function updates one specific digit on the TM1638 display in fixed address mode.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param data Byte representing the segment states for the target digit.
 * @param address Target digit address on the display (0 to 15).
 *
 * @return Error flags (bitfield):
 *         Bit 0: Address was out of range and corrected.
 */
uint8_t TM1638_SetFixedAddress(TM1638_t *tm, uint8_t data, uint8_t address);

/**
 * @brief Write multiple segment data in address increment mode.
 *
 * Sends an array of bytes to the TM1638, starting from the specified address.
 * Each byte represents the state of segments for one LED/digit.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param segments Array of segment data (1 to 16 bytes).
 * @param length Number of bytes to write.
 * @param address Starting address on the display (0 to 15).
 *
 * @return Error flags (bitfield):
 *          Bit 0: Starting address was invalid and corrected
 *          Bit 1: Length exceeded remaining addresses and corrected
 *          Bit 2: Length was zero and corrected to 1
 */
uint8_t TM1638_Set8SegmentsAndLeds(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t address);

/**
 * @brief Write segments 1 to 8 and overwrite SEG9 and SEG10 with 0.
 *
 * Sends an array of bytes to the TM1638 starting at the specified position.
 * Each byte represents one digit; SEG9 and SEG10 are always cleared.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param segments Array of segment data (1 to 8 bytes).
 * @param length Number of digits to write. It must be 1 to 8 and <= (8 - pos).
 * @param pos Starting position on the display (0 to 7).
 *
 * @return Error flags (bitfield):
 *          Bit 0: Starting position was invalid and corrected
 *          Bit 1: Length exceeded remaining digits and corrected
 *          Bit 2: Length was zero and corrected to 1
 */
uint8_t TM1638_Set8Segments_OverWriteLeds(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos);

/**
 * @brief Write up to 8 digits to the TM1638 display without altering SEG9 and SEG10.
 *
 * This function writes an array of segment data starting from a specified position (0 to 7).
 * Only SEG1 to SEG8 are affected; SEG9 and SEG10 remain unchanged.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param segments Array of bytes representing segment states for the digits.
 * @param length Number of digits to write. It must be 1 to 8 and <= (8 - pos).
 * @param pos Starting position on the display (0 to 7).
 *
 * @return Error flags (bitfield):
 *         Bit 0: Starting position was out of range and corrected.
 *         Bit 1: Length exceeded remaining digits and corrected.
 *         Bit 2: Length was zero and corrected to 1.
 */
uint8_t TM1638_Set8Segments(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos);

/**
 * @brief Set the first 4 digits (Grid 1 to Grid 4) of the TM1637 display.
 *
 * This function writes the provided segment data to the first four digits
 * (Grid 1 to Grid 4) of the display. Each digit is represented by one byte
 * in the segments array, and the corresponding segment data is written
 * to the appropriate fixed address.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param segments Array of 4 bytes representing segment data for Grid 1 to Grid 4.
 *                Each byte represents the segment states for one digit.
 */
void TM1638_Set8Segments_4Digits_1st(TM1638_t *tm, uint8_t segments[]);

/**
 * @brief Set digits 5 to 8 (Grid 5 to Grid 8) of the TM1637 display.
 *
 * This function writes the provided segment data to the second group of
 * four digits (Grid 5 to Grid 8) of the display. Each byte in the segments
 * array represents the segment states for one digit and is written to
 * the corresponding fixed address.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param segments Array of 4 bytes representing segment data for Grid 5 to Grid 8.
 */
void TM1638_Set8Segments_4Digits_2nd(TM1638_t *tm, uint8_t segments[]);

/**
 * @brief Set the 8 LEDs connected to SEG9.
 *
 * Each bit in the input byte controls one LED on SEG9:
 *   Bit 0: LED at SEG9/GRID1
 *   Bit 1: LED at SEG9/GRID2
 *   ...
 *   Bit 7: LED at SEG9/GRID8
 *
 * @note SEG10 LEDs are not affected and will be set to 0.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param data 8-bit value controlling the LEDs on SEG9.
 */
void TM1638_Set8Leds(TM1638_t *tm, uint8_t data);

/**
 * @brief Set the 16 LEDs connected to SEG9 and SEG10.
 *
 * Each bit pair in the 16-bit input controls one LED:
 *   Bit 0: LED at SEG9 and GRID1
 *   Bit 1: LED at SEG10 and GRID1
 *   Bit 2: LED at SEG9 and GRID2
 *   Bit 3: LED at SEG10 and GRID2
 *   ...
 *   Bit 14: LED at SEG9 and GRID8
 *   Bit 15: LED at SEG10 and GRID8
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param data 16-bit value controlling the LEDs on SEG9 and SEG10.
 */
void TM1638_Set16Leds(TM1638_t *tm, uint16_t data);

/**
 * @brief Scan buttons connected to K1, K2, and K3 lines.
 *
 * Reads the state of all buttons in multi-press mode.
 * The function retrieves 4 bytes representing the button states.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param key Pointer to an array of 4 bytes where the button states will be stored.
 */
void TM1638_Get24Buttons(TM1638_t *tm, uint8_t *key);

/**
 * @brief Scan buttons connected to K3 lines (1 to 8 buttons).
 *
 * Reads the state of buttons connected to K3 and combines them into a single byte.
 * Each bit of the returned byte represents one button state.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @param key Pointer to a byte where the combined button states will be stored.
 */
void TM1638_Get8Buttons(TM1638_t *tm, uint8_t *key);

/**
 * @brief Get the state of buttons connected to K3 as a single byte.
 *
 * This function reads buttons on K3 lines (1 to 8) and returns
 * their states combined into a single byte. Each bit represents one button.
 *
 * @param tm Pointer to TM1638 handle structure.
 * @return Byte representing the state of buttons.
 */
uint8_t TM1638_Return8Buttons(TM1638_t *tm);

#pragma library tm1638.lib
#endif
