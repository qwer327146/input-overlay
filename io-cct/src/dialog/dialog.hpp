/**
 * Created by univrsal on 23.05.2018.
 * This file is part of input-overlay which is licensed
 * under the MOZILLA PUBLIC LICENSE 2.0 - http://www.gnu.org/licenses
 * github.com/univrsal/input-overlay
 */

#pragma once

#include "../util/sdl_helper.hpp"
#include "elements/gui_element.hpp"
#include "elements/label.hpp"
#include <string>
#include <vector>
#include <memory>

#define DIALOG_DRAGGABLE 1 << 0 /* Allow moving by dragging the title bar*/
#define DIALOG_CENTERED 1 << 1  /* Always center on window resize */
#define DIALOG_TEXTINPUT 1 << 2 /* Hint SDL to read text input */
#define DIALOG_TOP_MOST 1 << 3  /* Draws background tint */
#define DIALOG_FLUID 1 << 4     /* Dialog adapts to window size. Includes DIALOG_CENTERED */

#define FLUID_BORDER 32

class sdl_helper;

class gui_element;

class dialog {
public:
	dialog(sdl_helper *sdl, SDL_Rect size, const std::string &title);

	dialog(sdl_helper *sdl, SDL_Point size, const std::string &title);

	virtual ~dialog();

	virtual void init();

	virtual void draw_background();

	virtual void draw_foreground();

	virtual void close();

	virtual bool handle_events(SDL_Event *event);

	virtual void action_performed(int8_t action_id);

	void add(gui_element *e);

	void set_dimension(uint16_t w, uint16_t h);

	void set_flags(uint16_t flags);

	void reload_lang();

	void change_focus(int8_t id);

	SDL_Point position() const;

	sdl_helper *helper() const;

	int get_left() const;

	int get_top() const;

	int get_right() const;

	int get_bottom() const;

protected:
	/* Tab handling */
	gui_element *m_focused_element = nullptr;
	int8_t m_focused_element_id = 0;

	std::vector<std::unique_ptr<gui_element>> m_screen_elements;
	std::vector<gui_element *> m_tab_items;
	std::string m_title;

	int m_offset_x, m_offset_y{};
	bool m_is_dragging = false;
	uint16_t m_flags = 0x0000;

	sdl_helper *m_helper;
	SDL_Rect m_dimensions{};
	SDL_Rect m_title_bar{};
};
