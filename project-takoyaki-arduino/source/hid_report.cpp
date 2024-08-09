#include "hid_report.hpp"

void HIDReportMouseParser::initialize() {
  usb.Init();
  hid_mouse.SetReportParser(0, this);
}

mouse_report HIDReportMouseParser::parse_report() {
  m_current_report.dx = 0;
  m_current_report.dy = 0;
  m_current_report.dz = 0;

  usb.Task();

  return m_current_report;
}

void HIDReportMouseParser::Parse(USBHID* hid, bool is_rpt_id, uint8_t len, uint8_t* buf) {
  for (uint16_t button = 1; button <= 16; button <<= 1) {
    if (buf[0] & button) {
      if (!(m_previous_button_state & button)) {
        switch (button) {
          case MOUSE_BUTTON_LEFT:
            m_current_report.mouse_button_left = true;
            break;
          case MOUSE_BUTTON_RIGHT:
            m_current_report.mouse_button_right = true;
            break;
          case MOUSE_BUTTON_MIDDLE:
            m_current_report.mouse_button_middle = true;
            break;
          case MOUSE_BUTTON_4:
            m_current_report.mouse_button_4 = true;
            break;
          case MOUSE_BUTTON_5:
            m_current_report.mouse_button_5 = true;
            break;
          default:
            break;
        }
      } else {
        switch (button) {
          case MOUSE_BUTTON_LEFT:
            m_current_report.mouse_button_left = false;
            break;
          case MOUSE_BUTTON_RIGHT:
            m_current_report.mouse_button_right = false;
            break;
          case MOUSE_BUTTON_MIDDLE:
            m_current_report.mouse_button_middle = false;
            break;
          case MOUSE_BUTTON_4:
            m_current_report.mouse_button_4 = false;
            break;
          case MOUSE_BUTTON_5:
            m_current_report.mouse_button_5 = false;
            break;
          default:
            break;
        }
      }
    }
  }

  const auto dx = static_cast<int8_t>(buf[1]);
  const auto dy = static_cast<int8_t>(buf[3]);
  const auto dz = static_cast<int8_t>(buf[5]);

  if (dx != 0 || dy != 0 || dz != 0) {
    m_current_report.dx = dx;
    m_current_report.dy = dy;
    m_current_report.dz = dz;
  }

  m_previous_button_state = buf[0];
}