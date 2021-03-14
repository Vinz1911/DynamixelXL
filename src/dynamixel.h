/*
 * Dynamixel
 *
 * Copyright (C) 2020 Vinzenz Weist Vinz1911@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef DYNAMIXEL_DYNAMIXEL_H
#define DYNAMIXEL_DYNAMIXEL_H

#include <cstdio>
#include <cstdint>
#include <vector>
#include <dynamixel_sdk.h>
#include "dynamixel_address_table.h"

class Dynamixel {
// public declaration
public:
    /**
     * initialize dynamixel class
     * @param t_device_name the device path | default -> "/dev/ttyACM0"
     * @param t_protocol_version the protocol version | default -> 2.0
     * @param t_baud_rate the baudrate | default -> 1_000_000
     */
    explicit Dynamixel(const char* t_device_name = "/dev/ttyACM0", float t_protocol_version = 2.0, int t_baud_rate = 1000000):
            m_device_name(t_device_name),
            m_protocol_version(t_protocol_version),
            m_baud_rate(t_baud_rate) {
    };
    /**
     * open a connection to the dynamixel
     * @return true if success otherwise false
     */
    bool set_open();
    /**
     * close a connection to the dynamixel
     */
    void set_close();
    /**
     * reboot a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     */
    void set_reboot(uint8_t t_dxl_id);
    /**
     * factory reset a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     */
    void set_factory_reset(uint8_t t_dxl_id);
    /**
     * get the torque of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the torque value
     */
    uint8_t get_torque(uint8_t t_dxl_id);
    /**
     * get the led status of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the led status value
     */
    uint8_t get_led(uint8_t t_dxl_id);
    /**
     * get the current id of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel id
     */
    uint8_t get_id(uint8_t t_dxl_id);
    /**
     * get the current shadow id of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel shadow id
     */
    uint8_t get_shadow_id(uint8_t t_dxl_id);
    /**
     * get the current drive mode of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel drive mode value
     */
    uint8_t get_drive_mode(uint8_t t_dxl_id);
    /**
     * get the current operating mode of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel operating mode value
     */
    uint8_t get_operating_mode(uint8_t t_dxl_id);
    /**
     * get the current firmware version of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel firmware version
     */
    uint8_t get_firmware_version(uint8_t t_dxl_id);
    /**
     * get the current protocol type of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel protocol version
     */
    uint8_t get_protocol_type(uint8_t t_dxl_id);
    /**
     * get the current present temperature of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel present temperature
     */
    uint8_t get_present_temperature(uint8_t t_dxl_id);
    /**
     * get the current t_gain P-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel velocity P_GAIN value
     */
    uint16_t get_velocity_kp_gain(uint8_t t_dxl_id);
    /**
     * get the current velocity I-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel velocity I-GAIN value
     */
     uint16_t get_velocity_ki_gain(uint8_t t_dxl_id);
    /**
     * get the current t_position P-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel t_position P-GAIN value
     */
    uint16_t get_position_kp_gain(uint8_t t_dxl_id);
    /**
     * get the current t_position I-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel t_position I-GAIN value
     */
    uint16_t get_position_ki_gain(uint8_t t_dxl_id);
    /**
     * get the current t_position D-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel t_position D-GAIN value
     */
    uint16_t get_position_kd_gain(uint8_t t_dxl_id);
    /**
     * get the current feedforward first-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel feedforward first-GAIN value
     */
    uint16_t get_feedforward_first_gain(uint8_t t_dxl_id);
    /**
     * get the current feedforward second-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel feedforward second-GAIN value
     */
    uint16_t get_feedforward_second_gain(uint8_t t_dxl_id);
    /**
     * get the model number of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel model number
     */
    uint16_t get_model_number(uint8_t t_dxl_id);
    /**
     * get the present load of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel present load
     */
    uint16_t get_present_load(uint8_t t_dxl_id);
    /**
     * get the input voltage of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel input voltage value
     */
    uint16_t get_present_input_voltage(uint8_t t_dxl_id);
    /**
     * get the real time tick of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel real time tick
     */
    uint16_t get_realtime_tick(uint8_t t_dxl_id);
    /**
     * get the present pwm of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel pwm value
     */
    uint32_t get_present_pwm(uint8_t t_dxl_id);
    /**
     * get the present velocity of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel present velocity value
     */
    uint32_t get_present_velocity(uint8_t t_dxl_id);
    /**
     * get the present t_position of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @return the dynamixel present t_position value
     */
    uint32_t get_present_position(uint8_t t_dxl_id);
    /**
     * set the torque of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_torque_state enable or disable
     */
    void set_torque(uint8_t t_dxl_id, bool t_torque_state);
    /**
     * set the led of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_led_state enable or disable
     */
    void set_led(uint8_t t_dxl_id, bool t_led_state);
    /**
     * set the id of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param value id value -> 0-255
     */
    void set_id(uint8_t t_dxl_id, uint8_t t_value);
    /**
     * set the shadow id of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param value the id value -> 0-253 | 255 disable's the shadow id
     */
    void set_shadow_id(uint8_t t_dxl_id, uint8_t t_value);
    /**
     * set the operating mode of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_control_mode control mode value -> see dynamixel table
     */
    void set_operating_mode(uint8_t t_dxl_id, uint8_t t_control_mode);
    /**
     * set the operating mode of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_drive_mode drive mode value -> see dynamixel table
     */
    void set_drive_mode(uint8_t t_dxl_id, uint8_t t_drive_mode);
    /**
     * set the velocity P-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param velocity I-GAIN value -> 0 - 16384
     */
    void set_velocity_kp_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the velocity I-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param velocity P-GAIN value -> 0 - 16384
     */
    void set_velocity_ki_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the t_position P-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_position P-GAIN value -> 0 - 16384
     */
    void set_position_kp_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the t_position I-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_position I-GAIN value -> 0 - 16384
     */
    void set_position_ki_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the t_position D-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_position D-GAIN value -> 0 - 16384
     */
    void set_position_kd_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the feedforward first-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param feedforward first-GAIN value -> 0 - 16384
     */
    void set_feedforward_first_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the feedforward second-GAIN of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param feedforward second-GAIN value -> 0 - 16384
     */
    void set_feedforward_second_gain(uint8_t t_dxl_id, uint16_t t_gain);
    /**
     * set the pwm of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param pwm value -> 0-885
     */
    void set_goal_pwm(uint8_t t_dxl_id, uint16_t t_pwm);
    /**
     * set the goal velocity of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param goal velocity value -> 0-265
     */
    void set_goal_velocity(uint8_t t_dxl_id, uint32_t t_velocity);
    /**
     * set the goal t_position of a dynamixel
     * @param t_dxl_id the identifier of the dynamixel
     * @param t_position goal t_position value -> 0-4096
     */
    void set_goal_position(uint8_t t_dxl_id, uint32_t t_position);
    /**
     * set the goal velocity of two dynamixel's
     * @param t_dxl1_id the identifier of the dynamixel
     * @param t_dxl2_id the identifier of the dynamixel
     * @param t_dxl1_velocity goal velocity value -> 0-265
     * @param t_dxl2_velocity goal velocity value -> 0-265
     */
    void set_group_goal_velocity(uint8_t t_dxl1_id, uint8_t t_dxl2_id, uint32_t t_dxl1_velocity, uint32_t t_dxl2_velocity);
    /**
     * set the goal t_position of two dynamixel's
     * @param t_dxl1_id the identifier of the dynamixel
     * @param t_dxl2_id the identifier of the dynamixel
     * @param t_dxl1_position goal t_position value -> 0-4096
     * @param t_dxl2_position goal t_position value -> 0-4096
     */
    void set_group_goal_position(uint8_t t_dxl1_id, uint8_t t_dxl2_id, uint32_t t_dxl1_position, uint32_t t_dxl2_position);

// private declaration
private:
    /**
     * the device path
     */
    const char* m_device_name;
    /**
     * the dynamixel protocol version
     */
    float m_protocol_version;
    /**
     * the dynamixel baudrate
     */
    int m_baud_rate;
    /**
     * set up packet handler
     */
    dynamixel::PacketHandler *m_packet_handler = dynamixel::PacketHandler::getPacketHandler(m_protocol_version);
    /**
     * set up port handler
     */
    dynamixel::PortHandler *m_port_handler = dynamixel::PortHandler::getPortHandler(m_device_name);
    /**
     * set up bulk write
     */
    dynamixel::GroupBulkWrite m_group_bulk_write = dynamixel::GroupBulkWrite(m_port_handler, m_packet_handler);
    /**
     * validate the transmitted result
     * @param t_dxl_result the result value
     * @param t_dxl_error the 'possible' error value
     */
    void m_get_validated_result(uint8_t t_dxl_result, uint8_t t_dxl_error);
    /**
     * validate given parameters
     * @param t_dxl1_id dynamixel first identifier
     * @param t_dxl2_id dynamixel second identifier
     * @param t_dxl1_param dynamixel first parameter
     * @param t_dxl2_param dynamixel second parameter
     */
    void m_get_validated_param(uint8_t t_dxl1_id, uint8_t t_dxl2_id, uint8_t t_dxl1_param, uint8_t t_dxl2_param);
    /**
     * map a value and return it as 4 byte data array
     * @param value the input value
     * @return the mapped array
     */
    std::vector<uint8_t> m_get_group_data(uint32_t t_value);
    /**
     * read from a dynamixel small register
     * @param t_dxl_id the dynamixel identifier
     * @param t_address the address to be read from
     * @return the value which was read
     */
    uint8_t m_get_small_register(uint8_t t_dxl_id, uint16_t t_address);
    /**
     * read from a dynamixel medium register
     * @param t_dxl_id the dynamixel identifier
     * @param t_address the address to be read from
     * @return the value which was read
     */
    uint16_t m_get_medium_register(uint8_t t_dxl_id, uint16_t t_address);
    /**
     * read from a dynamixel large register
     * @param t_dxl_id the dynamixel identifier
     * @param t_address the address to be read from
     * @return the value which was read
     */
    uint32_t m_get_large_register(uint8_t t_dxl_id, uint16_t t_address);
    /**
     * write on dynamixel small register
     * @param t_dxl_id dynamixel identifier
     * @param t_address the address to write to
     * @param value the value to be written -> small write uint8_t value
     */
    void m_set_small_register(uint8_t t_dxl_id, uint16_t t_address, uint8_t t_value);
    /**
     * write on dynamixel medium register
     * @param t_dxl_id dynamixel identifier
     * @param t_address the address to write to
     * @param t_value the value to be written -> medium write uint16_t value
     */
    void m_set_medium_register(uint8_t t_dxl_id, uint16_t t_address, uint16_t t_value);
    /**
     * write on dynamixel large register
     * @param t_dxl_id dynamixel identifier
     * @param t_address the address to write to
     * @param t_value the value to be written -> large write uint32_t value
     */
    void m_set_large_register(uint8_t t_dxl_id, uint16_t t_address, uint32_t t_value);
    /**
     * write on a group register (write against two dynamixel)
     * @param t_dxl1_id first dynamixel identifier
     * @param t_dxl2_id second dynamixel identifier
     * @param t_address the address to be written
     * @param t_dxl1_value the t_value to be written for the first dynamixel
     * @param t_dxl2_value the t_value to be written for the second dynamixel
     */
    void m_set_group_register(uint8_t t_dxl1_id, uint8_t t_dxl2_id, uint16_t t_address, uint8_t *t_dxl1_value, uint8_t *t_dxl2_value);
};

#endif
