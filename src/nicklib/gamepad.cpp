#include "nicklib/gamepad.hpp"

nicklib::Gamepad::Gamepad(pros::controller_id_e_t id)
    : controller(std::make_unique<pros::Controller>(id)) {}
    // : controller(new pros::Controller(id)) {}

void nicklib::Gamepad::update() {
    // Get the input value for the stick axes
    for (int i = 0; i < 4; i++) {
        pros::controller_analog_e_t stick = static_cast<pros::controller_analog_e_t>(i);
        *this->ptrSticksArr[i] = controller->get_analog(stick) / 127.0;
    }

    // Get the status for the buttons
    for (int i = 0; i < 12; i++) {
        /** NOTE: add 6 to i to match the pros::controller_digital_e_t enum in misc.h */
        pros::controller_digital_e_t button = static_cast<pros::controller_digital_e_t>(i + 6);
        (*this->ptrButtonsArr[i]).setStatus(controller->get_digital(button));
    }
}