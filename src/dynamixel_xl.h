/*
 * DynamixelXL
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

#ifndef DYNAMIXEL_DYNAMIXEL_XL_H
#define DYNAMIXEL_DYNAMIXEL_XL_H

#include <cstdio>
#include <cstdint>
#include <vector>
#include <dynamixel_sdk.h>
#include "dynamixel_table.cpp"

class DynamixelXL {
// public declaration
public:
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
     * @param dxl_id the identifier of the dynamixel
     */
    void set_reboot(uint8_t dxl_id);
    /**
     * factory reset a dynamixel
     * @param dxl_id the identifier of the dynamixel
     */
    void set_factory_reset(uint8_t dxl_id);
    /**
     * get the torque of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the torque value
     */
    uint8_t get_torque(uint8_t dxl_id);
    /**
     * get the led status of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the led status value
     */
    uint8_t get_led(uint8_t dxl_id);
    /**
     * get the current id of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel id
     */
    uint8_t get_id(uint8_t dxl_id);
    /**
     * get the current shadow id of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel shadow id
     */
    uint8_t get_shadow_id(uint8_t dxl_id);
    /**
     * get the current drive mode of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel drive mode value
     */
    uint8_t get_drive_mode(uint8_t dxl_id);
    /**
     * get the current operating mode of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel operating mode value
     */
    uint8_t get_operating_mode(uint8_t dxl_id);
    /**
     * get the current firmware version of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel firmware version
     */
    uint8_t get_firmware_version(uint8_t dxl_id);
    /**
     * get the current protocol type of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel protocol version
     */
    uint8_t get_protocol_type(uint8_t dxl_id);
    /**
     * get the current present temperature of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel present temperature
     */
    uint8_t get_present_temperature(uint8_t dxl_id);
    /**
     * get the current velocity P-GAIN of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel velocity P_GAIN value
     */
    uint16_t get_velocity_kp_gain(uint8_t dxl_id);
    /**
     * get the current velocity I-GAIN of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel velocity I-GAIN value
     */
    uint16_t get_velocity_ki_gain(uint8_t dxl_id);
    /**
     * get the model number of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel model number
     */
    uint16_t get_model_number(uint8_t dxl_id);
    /**
     * get the present load of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel present load
     */
    uint16_t get_present_load(uint8_t dxl_id);
    /**
     * get the input voltage of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel input voltage value
     */
    uint16_t get_present_input_voltage(uint8_t dxl_id);
    /**
     * get the real time tick of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel real time tick
     */
    uint16_t get_realtime_tick(uint8_t dxl_id);
    /**
     * get the present pwm of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel pwm value
     */
    uint32_t get_present_pwm(uint8_t dxl_id);
    /**
     * get the present velocity of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel present velocity value
     */
    uint32_t get_present_velocity(uint8_t dxl_id);
    /**
     * get the present position of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @return the dynamixel present position value
     */
    uint32_t get_present_position(uint8_t dxl_id);
    /**
     * set the torque of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param torque_state enable or disable
     */
    void set_torque(uint8_t dxl_id, bool torque_state);
    /**
     * set the led of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param led_state enable or disable
     */
    void set_led(uint8_t dxl_id, bool led_state);
    /**
     * set the id of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param value id value -> 0-255
     */
    void set_id(uint8_t dxl_id, uint8_t value);
    /**
     * set the shadow id of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param value the id value -> 0-253 | 255 disable's the shadow id
     */
    void set_shadow_id(uint8_t dxl_id, uint8_t value);
    /**
     * set the operating mode of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param control_mode control mode value -> see dynamixel table
     */
    void set_operating_mode(uint8_t dxl_id, uint8_t control_mode);
    /**
     * set the operating mode of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param drive_mode drive mode value -> see dynamixel table
     */
    void set_drive_mode(uint8_t dxl_id, uint8_t drive_mode);
    /**
     * set the velocity P-GAIN of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param velocity I-GAIN value -> 0 - 16384
     */
    void set_velocity_kp_gain(uint8_t dxl_id, uint16_t gain);
    /**
     * set the velocity I-GAIN of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param velocity P-GAIN value -> 0 - 16384
     */
    void set_velocity_ki_gain(uint8_t dxl_id, uint16_t gain);
    /**
     * set the goal velocity of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param goal velocity value -> 0-265
     */
    void set_goal_velocity(uint8_t dxl_id, uint32_t velocity);
    /**
     * set the goal velocity of two dynamixel's
     * @param dxl1_id the identifier of the dynamixel
     * @param dxl2_id the identifier of the dynamixel
     * @param dxl1_velocity goal velocity value -> 0-265
     * @param dxl2_velocity goal velocity value -> 0-265
     */
    void set_group_goal_velocity(uint8_t dxl1_id, uint8_t dxl2_id, uint32_t dxl1_velocity, uint32_t dxl2_velocity);
    /**
     * set the goal position of two dynamixel's
     * @param dxl1_id the identifier of the dynamixel
     * @param dxl2_id the identifier of the dynamixel
     * @param dxl1_position goal position value -> 0-4096
     * @param dxl2_position goal position value -> 0-4096
     */
    void set_group_goal_position(uint8_t dxl1_id, uint8_t dxl2_id, uint32_t dxl1_position, uint32_t dxl2_position);
    /**
     * set the goal position of a dynamixel
     * @param dxl_id the identifier of the dynamixel
     * @param position goal position value -> 0-4096
     */
    void set_goal_position(uint8_t dxl_id, uint32_t position);
    /**
     * initialize dynamixel class
     * @param t_device_name the device path | default -> "/dev/ttyACM0"
     * @param t_protocol_version the protocol version | default -> 2.0
     * @param t_baud_rate the baudrate | default -> 1_000_000
     */
    explicit DynamixelXL(const char* t_device_name = "/dev/ttyACM0", float t_protocol_version = 2.0, int t_baud_rate = 1000000):
            m_device_name(t_device_name),
            m_protocol_version(t_protocol_version),
            m_baud_rate(t_baud_rate) {
    };

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
     * @param dxl_result the result value
     * @param dxl_error the 'possible' error value
     */
    void m_get_validated_result(uint8_t dxl_result, uint8_t dxl_error);
    /**
     * validate given parameters
     * @param dxl1_id dynamixel first identifier
     * @param dxl2_id dynamixel second identifier
     * @param dxl1_param dynamixel first parameter
     * @param dxl2_param dynamixel second parameter
     */
    void m_get_validated_param(uint8_t dxl1_id, uint8_t dxl2_id, uint8_t dxl1_param, uint8_t dxl2_param);
    /**
     * map a value and return it as 4 byte data array
     * @param value the input value
     * @return the mapped array
     */
    std::vector<uint8_t> m_get_group_data(uint32_t value);
    /**
     * read from a dynamixel small register
     * @param dxl_id the dynamixel identifier
     * @param address the address to be read from
     * @return the value which was read
     */
    uint8_t m_get_small_register(uint8_t dxl_id, uint16_t address);
    /**
     * read from a dynamixel medium register
     * @param dxl_id the dynamixel identifier
     * @param address the address to be read from
     * @return the value which was read
     */
    uint16_t m_get_medium_register(uint8_t dxl_id, uint16_t address);
    /**
     * read from a dynamixel large register
     * @param dxl_id the dynamixel identifier
     * @param address the address to be read from
     * @return the value which was read
     */
    uint32_t m_get_large_register(uint8_t dxl_id, uint16_t address);
    /**
     * write on dynamixel small register
     * @param dxl_id dynamixel identifier
     * @param address the address to write to
     * @param value the value to be written -> small write uint8_t value
     */
    void m_set_small_register(uint8_t dxl_id, uint16_t address, uint8_t value);
    /**
     * write on dynamixel medium register
     * @param dxl_id dynamixel identifier
     * @param address the address to write to
     * @param value the value to be written -> medium write uint16_t value
     */
    void m_set_medium_register(uint8_t dxl_id, uint16_t address, uint16_t value);
    /**
     * write on dynamixel large register
     * @param dxl_id dynamixel identifier
     * @param address the address to write to
     * @param value the value to be written -> large write uint32_t value
     */
    void m_set_large_register(uint8_t dxl_id, uint16_t address, uint32_t value);
    /**
     * write on a group register (write against two dynamixel)
     * @param dxl1_id first dynamixel identifier
     * @param dxl2_id second dynamixel identifier
     * @param address the address to be written
     * @param dxl1_value the value to be written for the first dynamixel
     * @param dxl2_value the value to be written for the second dynamixel
     */
    void m_set_group_register(uint8_t dxl1_id, uint8_t dxl2_id, uint16_t address, uint8_t *dxl1_value, uint8_t *dxl2_value);
};

#endif //DYNAMIXEL_DYNAMIXEL_XL_H
