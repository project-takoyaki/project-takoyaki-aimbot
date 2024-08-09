#pragma once

#include <hiduniversal.h>
#include <usbhid.h>

inline USB usb;
inline HIDUniversal hid_mouse(&usb);

struct mouse_report {
  bool mouse_button_left : 1;
  bool mouse_button_right : 1;
  bool mouse_button_middle : 1;
  bool mouse_button_4 : 1;
  bool mouse_button_5 : 1;

  int8_t dx;
  int8_t dy;
  int8_t dz;
};

enum mouse_button {
  MOUSE_BUTTON_LEFT = 0x01,
  MOUSE_BUTTON_RIGHT = 0x02,
  MOUSE_BUTTON_MIDDLE = 0x04,
  MOUSE_BUTTON_4 = 0x08,
  MOUSE_BUTTON_5 = 0x10
};

class HIDReportMouseParser : public HIDReportParser {
  public:
    void initialize();

    mouse_report parse_report();

    virtual ~HIDReportMouseParser() = default;

  protected:
    void Parse(USBHID* hid, bool is_rpt_id, uint8_t len, uint8_t* buf) override;

  private:
    uint8_t m_previous_button_state = 0;
    mouse_report m_current_report = { };
};
