#include "ui.hpp"
#include "ui_newexternalapp.hpp"
#include "ui_navigation.hpp"
#include "external_app.hpp"

namespace ui::external_app::newexternalapp {
void initialize_app(ui::NavigationView& nav) {
    nav.push<NewExternalAppView>();
}
}  // namespace ui::external_app::newexternalapp

extern "C" {

__attribute__((section(".external_app.app_newexternalapp.application_information"), used)) application_information_t _application_information_newexternalapp = {
    /*.memory_location = */ (uint8_t*)0x00000000,
    /*.externalAppEntry = */ ui::external_app::newexternalapp::initialize_app,
    /*.header_version = */ CURRENT_HEADER_VERSION,
    /*.app_version = */ VERSION_MD5,

    /*.app_name = */ "newexternalapp",
    /*.bitmap_data = */ {
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x80,
        0x01,
        0x80,
        0x01,
        0x80,
        0x01,
        0x80,
        0x01,
        0xF8,
        0x1F,
        0xF8,
        0x1F,
        0x80,
        0x01,
        0x80,
        0x01,
        0x80,
        0x01,
        0x80,
        0x01,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
    },
    /*.icon_color = */ ui::Color::green().v,
    /*.menu_location = */ app_location_t::RX,

    /*.m4_app_tag = portapack::spi_flash::image_tag_hackrf */ {'H', 'R', 'F', '1'},
    /*.m4_app_offset = */ 0x00000000,  // will be filled at compile time
};
}
