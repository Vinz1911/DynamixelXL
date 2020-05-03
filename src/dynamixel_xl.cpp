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

#include "dynamixel_xl.h"

/**
 * open a connection to the dynamixel
 * @return true if success otherwise false
 */
bool DynamixelXL::set_open() {
    return m_port_handler->openPort() && m_port_handler->setBaudRate(m_baud_rate);
}
/**
 * close a connection to the dynamixel
 */
void DynamixelXL::set_close() {
    m_port_handler->closePort();
}
/**
 * reboot a dynamixel
 * @param dxl_id the identifier of the dynamixel
 */
void DynamixelXL::set_reboot(uint8_t dxl_id) {
    uint8_t dxl_error;
    uint8_t dxl_result = m_packet_handler->reboot(m_port_handler, dxl_id, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
}
/**
 * factory reset a dynamixel
 * @param dxl_id the identifier of the dynamixel
 */
void DynamixelXL::set_factory_reset(uint8_t dxl_id) {
    uint8_t dxl_error;
    uint8_t dxl_result = m_packet_handler->factoryReset(m_port_handler, dxl_id, 0, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
}
/**
 * get the torque of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the torque value
 */
uint8_t DynamixelXL::get_torque(uint8_t dxl_id) {
    uint8_t dxl_torque = m_get_small_register(dxl_id, ADDR_XL_TORQUE);
    return dxl_torque;
}
/**
 * get the led status of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the led status value
 */
uint8_t DynamixelXL::get_led(uint8_t dxl_id) {
    uint8_t dxl_led = m_get_small_register(dxl_id, ADDR_XL_LED);
    return dxl_led;
}
/**
 * get the current id of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel id
 */
uint8_t DynamixelXL::get_id(uint8_t dxl_id) {
    uint8_t dxl_mid = m_get_small_register(dxl_id, ADDR_XL_ID);
    return dxl_mid;
}
/**
 * get the current shadow id of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel shadow id
 */
uint8_t DynamixelXL::get_shadow_id(uint8_t dxl_id) {
    uint8_t dxl_shadow_id = m_get_small_register(dxl_id, ADDR_XL_SHADOW_ID);
    return dxl_shadow_id;
}
/**
 * get the current drive mode of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel drive mode value
 */
uint8_t DynamixelXL::get_drive_mode(uint8_t dxl_id) {
    uint8_t dxl_drive_mode = m_get_small_register(dxl_id, ADDR_XL_DRIVE_MODE);
    return dxl_drive_mode;
}
/**
 * get the current operating mode of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel operating mode value
 */
uint8_t DynamixelXL::get_operating_mode(uint8_t dxl_id) {
    uint8_t dxl_operating_mode = m_get_small_register(dxl_id, ADDR_XL_OPERATING_MODE);
    return dxl_operating_mode;
}
/**
 * get the current firmware version of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel firmware version
 */
uint8_t DynamixelXL::get_firmware_version(uint8_t dxl_id) {
    uint8_t dxl_firmware_version = m_get_small_register(dxl_id, ADDR_XL_FIRMWARE_VERSION);
    return dxl_firmware_version;
}
/**
 * get the current protocol type of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel protocol version
 */
uint8_t DynamixelXL::get_protocol_type(uint8_t dxl_id) {
    uint8_t dxl_protocol_type = m_get_small_register(dxl_id, ADDR_XL_PROTOCOL_TYPE);
    return dxl_protocol_type;
}
/**
 * get the current present temperature of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel present temperature
 */
uint8_t DynamixelXL::get_present_temperature(uint8_t dxl_id) {
    uint8_t dxl_temperature = m_get_small_register(dxl_id, ADDR_XL_PRESENT_TEMPERATURE);
    return dxl_temperature;
}
/**
 * get the current velocity P-GAIN of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel velocity P_GAIN value
 */
uint16_t DynamixelXL::get_velocity_kp_gain(uint8_t dxl_id) {
    uint16_t dxl_gain = m_get_medium_register(dxl_id, ADDR_XL_VELOCITY_P_GAIN);
    return dxl_gain;
}
/**
 * get the current velocity I-GAIN of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel velocity I-GAIN value
 */
uint16_t DynamixelXL::get_velocity_ki_gain(uint8_t dxl_id) {
    uint16_t dxl_gain = m_get_medium_register(dxl_id, ADDR_XL_VELOCITY_I_GAIN);
    return dxl_gain;
}
/**
 * get the model number of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel model number
 */
uint16_t DynamixelXL::get_model_number(uint8_t dxl_id) {
    uint16_t dxl_model_number = m_get_medium_register(dxl_id, ADDR_XL_MODEL_NUMBER);
    return dxl_model_number;
}
/**
 * get the present load of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel present load
 */
uint16_t DynamixelXL::get_present_load(uint8_t dxl_id) {
    uint16_t dxl_load = m_get_medium_register(dxl_id, ADDR_XL_PRESENT_LOAD);
    return dxl_load;
}
/**
 * get the input voltage of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel input voltage value
 */
uint16_t DynamixelXL::get_present_input_voltage(uint8_t dxl_id) {
    uint16_t dxl_input_voltage = m_get_medium_register(dxl_id, ADDR_XL_PRESENT_INPUT_VOLTAGE);
    return dxl_input_voltage;
}
/**
 * get the real time tick of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel real time tick
 */
uint16_t DynamixelXL::get_realtime_tick(uint8_t dxl_id) {
    uint16_t dxl_realtime_tick = m_get_medium_register(dxl_id, ADDR_XL_REALTIME_TICK);
    return dxl_realtime_tick;
}
/**
 * get the present pwm of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel pwm value
 */
uint32_t DynamixelXL::get_present_pwm(uint8_t dxl_id) {
    uint32_t dxl_pwm = m_get_large_register(dxl_id, ADDR_XL_PRESENT_PWM);
    return dxl_pwm;
}
/**
 * get the present velocity of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel present velocity value
 */
uint32_t DynamixelXL::get_present_velocity(uint8_t dxl_id) {
    uint32_t dxl_velocity = m_get_large_register(dxl_id, ADDR_XL_PRESENT_VELOCITY);
    return dxl_velocity;
}
/**
 * get the present position of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @return the dynamixel present position value
 */
uint32_t DynamixelXL::get_present_position(uint8_t dxl_id) {
    uint32_t dxl_position = m_get_large_register(dxl_id, ADDR_XL_PRESENT_POSITION);
    return dxl_position;
}
/**
 * set the torque of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param torque_state enable or disable
 */
void DynamixelXL::set_torque(uint8_t dxl_id, bool torque_state) {
    m_set_small_register(dxl_id, ADDR_XL_TORQUE, torque_state);
}
/**
 * set the led of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param led_state enable or disable
 */
void DynamixelXL::set_led(uint8_t dxl_id, bool led_state) {
    m_set_small_register(dxl_id, ADDR_XL_LED, led_state);
}
/**
 * set the id of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param value id value -> 0-255
 */
void DynamixelXL::set_id(uint8_t dxl_id, uint8_t value) {
    m_set_small_register(dxl_id, ADDR_XL_ID, value);
}
/**
 * set the shadow id of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param value the id value -> 0-253 | 255 disable's the shadow id
 */
void DynamixelXL::set_shadow_id(uint8_t dxl_id, uint8_t value) {
    m_set_small_register(dxl_id, ADDR_XL_SHADOW_ID, value);
}
/**
 * set the operating mode of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param control_mode control mode value -> see dynamixel table
 */
void DynamixelXL::set_operating_mode(uint8_t dxl_id, uint8_t control_mode) {
    m_set_small_register(dxl_id, ADDR_XL_OPERATING_MODE, control_mode);
}
/**
 * set the operating mode of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param drive_mode drive mode value -> see dynamixel table
 */
void DynamixelXL::set_drive_mode(uint8_t dxl_id, uint8_t drive_mode) {
    m_set_small_register(dxl_id, ADDR_XL_DRIVE_MODE, drive_mode);
}
/**
 * set the velocity P-GAIN of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param velocity I-GAIN value -> 0 - 16384
 */
void DynamixelXL::set_velocity_kp_gain(uint8_t dxl_id, uint16_t gain) {
    m_set_medium_register(dxl_id, ADDR_XL_VELOCITY_P_GAIN, gain);
}
/**
 * set the velocity I-GAIN of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param velocity P-GAIN value -> 0 - 16384
 */
void DynamixelXL::set_velocity_ki_gain(uint8_t dxl_id, uint16_t gain) {
    m_set_medium_register(dxl_id, ADDR_XL_VELOCITY_I_GAIN, gain);
}
/**
 * set the goal velocity of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param goal velocity value -> 0-265
 */
void DynamixelXL::set_goal_velocity(uint8_t dxl_id, uint32_t velocity) {
    m_set_large_register(dxl_id, ADDR_XL_GOAL_VELOCITY, velocity);
}
/**
 * set the goal velocity of two dynamixel's
 * @param dxl1_id the identifier of the dynamixel
 * @param dxl2_id the identifier of the dynamixel
 * @param dxl1_velocity goal velocity value -> 0-265
 * @param dxl2_velocity goal velocity value -> 0-265
 */
void DynamixelXL::set_group_goal_velocity(uint8_t dxl1_id, uint8_t dxl2_id, uint32_t dxl1_velocity, uint32_t dxl2_velocity) {
    std::vector<uint8_t> dxl1_velocity_data = m_get_group_data(dxl1_velocity);
    std::vector<uint8_t> dxl2_velocity_data = m_get_group_data(dxl2_velocity);
    m_set_group_register(dxl1_id, dxl2_id, ADDR_XL_GOAL_VELOCITY, dxl1_velocity_data.data(), dxl2_velocity_data.data());
}
/**
 * set the goal position of two dynamixel's
 * @param dxl1_id the identifier of the dynamixel
 * @param dxl2_id the identifier of the dynamixel
 * @param dxl1_position goal position value -> 0-4096
 * @param dxl2_position goal position value -> 0-4096
 */
void DynamixelXL::set_group_goal_position(uint8_t dxl1_id, uint8_t dxl2_id, uint32_t dxl1_position, uint32_t dxl2_position) {
    std::vector<uint8_t> dxl1_position_data = m_get_group_data(dxl1_position);
    std::vector<uint8_t> dxl2_position_data = m_get_group_data(dxl2_position);
    m_set_group_register(dxl1_id, dxl2_id, ADDR_XL_GOAL_POSITION, dxl1_position_data.data(), dxl2_position_data.data());
}
/**
 * set the goal position of a dynamixel
 * @param dxl_id the identifier of the dynamixel
 * @param position goal position value -> 0-4096
 */
void DynamixelXL::set_goal_position(uint8_t dxl_id, uint32_t position) {
    m_set_large_register(dxl_id, ADDR_XL_GOAL_POSITION, position);
}

// MARK: - Private Functions to read/write to dynamixel register
/**
 * validate the transmitted result
 * @param dxl_result the result value
 * @param dxl_error the 'possible' error value
 */
void DynamixelXL::m_get_validated_result(uint8_t dxl_result, uint8_t dxl_error) {
    if (dxl_result != COMM_SUCCESS) {
        printf("%s", m_packet_handler->getTxRxResult(dxl_result));
    }
    if (dxl_error != 0) {
        printf("%s", m_packet_handler->getRxPacketError(dxl_error));
    }
}
/**
 * validate given parameters
 * @param dxl1_id dynamixel first identifier
 * @param dxl2_id dynamixel second identifier
 * @param dxl1_param dynamixel first parameter
 * @param dxl2_param dynamixel second parameter
 */
void DynamixelXL::m_get_validated_param(uint8_t dxl1_id, uint8_t dxl2_id, uint8_t dxl1_param, uint8_t dxl2_param) {
    if (!dxl1_param) {
        printf("failed: param not added for id: %i\n", dxl1_id);
    }
    if (!dxl2_param) {
        printf("failed: param not added for id: %i\n", dxl2_id);
    }
}
/**
 * map a value and return it as 4 byte data array
 * @param value the input value
 * @return the mapped array
 */
std::vector<uint8_t> DynamixelXL::m_get_group_data(uint32_t value) {
    std::vector<uint8_t> param_data = std::vector<uint8_t>(4);
    param_data.insert(param_data.begin() + 0, DXL_LOBYTE(DXL_LOWORD(value)));
    param_data.insert(param_data.begin() + 1, DXL_HIBYTE(DXL_LOWORD(value)));
    param_data.insert(param_data.begin() + 2, DXL_LOBYTE(DXL_HIWORD(value)));
    param_data.insert(param_data.begin() + 3, DXL_HIBYTE(DXL_HIWORD(value)));
    return param_data;
}
/**
 * read from a dynamixel small register
 * @param dxl_id the dynamixel identifier
 * @param address the address to be read from
 * @return the value which was read
 */
uint8_t DynamixelXL::m_get_small_register(uint8_t dxl_id, uint16_t address) {
    uint8_t dxl_error;
    uint8_t dxl_value;
    uint8_t dxl_result = m_packet_handler->read1ByteTxRx(m_port_handler, dxl_id, address, (uint8_t*)&dxl_value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
    return dxl_value;
}
/**
 * read from a dynamixel medium register
 * @param dxl_id the dynamixel identifier
 * @param address the address to be read from
 * @return the value which was read
 */
uint16_t DynamixelXL::m_get_medium_register(uint8_t dxl_id, uint16_t address) {
    uint8_t dxl_error;
    uint16_t dxl_value;
    uint8_t dxl_result = m_packet_handler->read2ByteTxRx(m_port_handler, dxl_id, address, (uint16_t*)&dxl_value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
    return dxl_value;
}
/**
 * read from a dynamixel large register
 * @param dxl_id the dynamixel identifier
 * @param address the address to be read from
 * @return the value which was read
 */
uint32_t DynamixelXL::m_get_large_register(uint8_t dxl_id, uint16_t address) {
    uint8_t dxl_error;
    uint32_t dxl_value;
    uint8_t dxl_result = m_packet_handler->read4ByteTxRx(m_port_handler, dxl_id, address, (uint32_t*)&dxl_value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
    return dxl_value;
}
/**
 * write on dynamixel small register
 * @param dxl_id dynamixel identifier
 * @param address the address to write to
 * @param value the value to be written -> small write uint8_t value
 */
void DynamixelXL::m_set_small_register(uint8_t dxl_id, uint16_t address, uint8_t value) {
    uint8_t dxl_error;
    uint8_t dxl_result = m_packet_handler->write1ByteTxRx(m_port_handler, dxl_id, address, value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
}
/**
 * write on dynamixel medium register
 * @param dxl_id dynamixel identifier
 * @param address the address to write to
 * @param value the value to be written -> medium write uint16_t value
 */
void DynamixelXL::m_set_medium_register(uint8_t dxl_id, uint16_t address, uint16_t value) {
    uint8_t dxl_error;
    uint8_t dxl_result = m_packet_handler->write2ByteTxRx(m_port_handler, dxl_id, address, value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
}
/**
 * write on dynamixel large register
 * @param dxl_id dynamixel identifier
 * @param address the address to write to
 * @param value the value to be written -> large write uint32_t value
 */
void DynamixelXL::m_set_large_register(uint8_t dxl_id, uint16_t address, uint32_t value) {
    uint8_t dxl_error;
    uint8_t dxl_result = m_packet_handler->write4ByteTxRx(m_port_handler, dxl_id, address, value, &dxl_error);
    m_get_validated_result(dxl_result, dxl_error);
}
/**
 * write on a group register (write against two dynamixel)
 * @param dxl1_id first dynamixel identifier
 * @param dxl2_id second dynamixel identifier
 * @param address the address to be written
 * @param dxl1_value the value to be written for the first dynamixel
 * @param dxl2_value the value to be written for the second dynamixel
 */
void DynamixelXL::m_set_group_register(uint8_t dxl1_id, uint8_t dxl2_id, uint16_t address, uint8_t *dxl1_value, uint8_t *dxl2_value) {
    uint8_t dxl1_param = m_group_bulk_write.addParam(dxl1_id, address, XL_GROUP_WRITE_LEN, dxl1_value);
    uint8_t dxl2_param = m_group_bulk_write.addParam(dxl2_id, address, XL_GROUP_WRITE_LEN, dxl2_value);
    m_get_validated_param(dxl1_id, dxl2_id, dxl1_param, dxl2_param);

    uint8_t dxl_result = m_group_bulk_write.txPacket();
    m_get_validated_result(dxl_result, 0);
    m_group_bulk_write.clearParam();
}