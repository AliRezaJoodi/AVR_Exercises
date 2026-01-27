/**
 * @file tm1637.h
 * @brief TM1637 6-digit 7-segment display driver.
 *
 * This file provides data structures and function prototypes
 * for controlling the TM1637 LED driver.
 *
 * @author AliReza Joodi
 * @see https://github.com/AliRezaJoodi
 */

#ifndef _TM1637_INCLUDED
#define _TM1637_INCLUDED


#include <stdint.h>
#include <io.h>
#include <delay.h>

#include <utility_bit.h>

/**
 * @note Default hardware macros can be overridden by the user.
 */
#include "hardware.h"

/**
 * @brief Half bit delay time in microseconds.
 *
 * This value defines the TM1637 clock timing.
 * One full clock period is equal to (TM1637_HALF_BIT_US * 4).
 *
 * @note Typical clock frequency is 450 kHz
 * @note Maximum clock frequency is 500 kHz
 */
#ifndef TM1637_HALF_BIT_US
#define TM1637_HALF_BIT_US     1
#endif

/**
 * @brief TM1637 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1637 driver.
 */ 
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    uint8_t           index;
} TM1637_Pin_t;

/**
 * @brief TM1637 device handle.
 *
 * This structure holds all configuration data required
 * to control one TM1637 device instance.
 *
 * Example usage:
 * @code
 * TM1637_t tm1;
 * 
 * tm1.clk.ddr  = &DDRC;
 * tm1.clk.port = &PORTC;
 * tm1.clk.pin  = &PINC;
 * tm1.clk.index = 0;
 * 
 * tm1.dio.ddr  = &DDRC;
 * tm1.dio.port = &PORTC;
 * tm1.dio.pin  = &PINC;
 * tm1.dio.index = 1;
 * @endcode
 */
typedef struct {
    TM1637_Pin_t clk;
    TM1637_Pin_t dio;
} TM1637_t;

/**
 * @brief Initialize the TM1637 device.
 *
 * This function initializes the TM1637 display interface.
 * It sets CLK and DIO lines to idle state, clears all display segments,
 * and turns the display ON with maximum brightness.
 *
 * @param tm Pointer to TM1637 handle structure.
 */
void TM1637_Config(TM1637_t *tm);

/**
 * @brief Send a command to the TM1637 device.
 *
 * This function sends a single command byte to the TM1637.
 * The command is transmitted using the TM1637 serial protocol.
 *
 * @param tm Pointer to TM1637 handle structure.
 * @param command Command byte to be sent.
 */
void TM1637_SendCommand(TM1637_t *tm, uint8_t command);

/**
 * @brief Set the TM1637 display ON/OFF and brightness level.
 *
 * This function controls the TM1637 display according to the datasheet.
 * It sets the display ON or OFF and adjusts the pulse width to control brightness.
 *
 * @param tm Pointer to TM1637 handle structure.
 * @param onoff Display ON/OFF control:
 *          0: Display OFF
 *          1: Display ON
 * @param brightness Display brightness level (pulse width):
 *          0: Pulse width is set as 1/16
 *          1: Pulse width is set as 2/16
 *          2: Pulse width is set as 4/16
 *          3: Pulse width is set as 10/16
 *          4: Pulse width is set as 11/16
 *          5: Pulse width is set as 12/16
 *          6: Pulse width is set as 13/16
 *          7: Pulse width is set as 14/16
 *
 * The command is sent using the TM1637 serial protocol with start and stop sequences.
 *
 * @return Error flags (bitfield):
 *          Bit 0: The onoff param was invalid and corrected
 *          Bit 1: The brightness param was invalid and corrected
 */
uint8_t TM1637_SetDisplay(TM1637_t *tm, uint8_t onoff, uint8_t brightness);

/**
 * @brief Clear all digits on the TM1637 display.
 *
 * This function resets all display segments to 0, effectively turning off all digits.
 * It writes zeros to all segment addresses using address auto-increment mode.
 *
 * @param tm Pointer to TM1637 handle structure.
 */
void TM1637_ResetSegments(TM1637_t *tm);

/**
 * @brief Write multiple segment data to the TM1637 using address auto-increment mode.
 *
 * This function writes an array of bytes to the display, starting from the specified address.
 * Each byte in the array represents the state of the segments for one digit.
 *
 * @param tm Pointer to TM1637 handle structure.
 * @param segments Array of 1 to 6 bytes representing segment data for the digits.
 * @param length Number of bytes to write (1 to 6).
 * @param address Starting digit address on the display (0 to 5):
 *          0: GRID1
 *          1: GRID2
 *          2: GRID3
 *          3: GRID4
 *          4: GRID5
 *          5: GRID6
 *
 * @return Error flags (bitfield):
 *          Bit 0: Starting address was out of range and corrected
 *          Bit 1: Length exceeded remaining digits and corrected
 *          Bit 2: Length was zero and corrected to 1
 */
uint8_t TM1637_SetSegments(TM1637_t *tm, uint8_t segments[], uint8_t length, uint8_t address);

/**
 * @brief Write segment data for 4 digits starting from the first digit.
 *
 * This is a helper function that writes 4 bytes of segment data to the
 * first four digits (GRID1 to GRID4) using address auto-increment mode.
 *
 * @param tm Pointer to TM1637 handle structure.
 * @param segments Array of 4 bytes representing segment data for digits 1 to 4.
 */
static inline void TM1637_SetSegments_4Digits(TM1637_t *tm, uint8_t segments[]){
    TM1637_SetSegments(tm, segments, 4, 0);
}

/**
 * @brief Write a single byte of segment data to a fixed digit address.
 *
 * This function sets the state of segments for one specific digit on the TM1637.
 * It uses fixed address mode, so only the specified digit is updated.
 *
 * @param tm Pointer to TM1637 handle structure.
 * @param data Byte representing the segment states for the target digit.
 * @param address Target digit address on the display (0 to 5):
 *          0: GRID1
 *          1: GRID2
 *          2: GRID3
 *          3: GRID4
 *          4: GRID5
 *          5: GRID6
 *
 * @return Error flags (bitfield):
 *         Bit 0: Address was out of range and corrected
 */
uint8_t TM1637_SetSegments_FixedAddress(TM1637_t *tm, uint8_t data, uint8_t address);


#pragma library tm1637.lib
#endif
