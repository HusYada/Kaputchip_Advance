// Kaputchip Advance by HusYada
#include "game.h"

void test_scene(bn::camera_ptr& camera, bn::sprite_text_generator text_generator) {
	// ----------------------------------------------------
	// Text Stuff
	// ----------------------------------------------------
	text_generator.set_left_alignment();
    bn::vector<bn::sprite_ptr, 64> dialog;
    bool typetext = false;
    int letter = 0;
    int sentence = 0;
    constexpr bn::string_view conversation[] = {
            " ",
            "RIGHT: increase tempo ",
            "Hello fellows! ",
            "Yeah, it's this guy ",
            "The documents write like horror stories, so I'm told ",
            "qweqwe ",
            "START: go to next scene ",
            "7 ",
        };
    // ----------------------------------------------------
    // Background Map Stuff
    // ----------------------------------------------------
	bn::regular_bg_ptr background_map = bn::regular_bg_items::test_map_3.create_bg(0,0);
	
	bn::sprite_ptr plyr_pixel = bn::sprite_items::cursor.create_sprite(0, 0);
	bn::sprite_ptr plyr_left_shadow = bn::sprite_items::cursor.create_sprite(0, 0);
    bn::sprite_ptr plyr_rght_shadow = bn::sprite_items::cursor.create_sprite(0, 0);
	plyr_left_shadow.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
    plyr_rght_shadow.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));

	const bn::regular_bg_map_item& map_item = bn::regular_bg_items::test_map_3.map_item();
	bn::regular_bg_map_cell valid_map_cell = map_item.cell(0, 0);
	int valid_tile_index = bn::regular_bg_map_cell_info(valid_map_cell).tile_index();

    bn::point leftshadowpos(255, 255);
    bn::point rghtshadowpos(256, 255);
    background_map.set_camera(camera);
    plyr_left_shadow.set_camera(camera);
    plyr_rght_shadow.set_camera(camera);

    // ----------------------------------------------------
	while(true)
    {
    	bn::point newleftshadowpos = leftshadowpos;
        bn::point newrghtshadowpos = rghtshadowpos;

        if(bn::keypad::left_pressed())
        {
            newleftshadowpos.set_x(newleftshadowpos.x() - 1);
            newrghtshadowpos.set_x(newrghtshadowpos.x() - 1);
            scrollx -= 1;
        }
        else if(bn::keypad::right_pressed())
        {
            newleftshadowpos.set_x(newleftshadowpos.x() + 1);
            newrghtshadowpos.set_x(newrghtshadowpos.x() + 1);
            scrollx += 1;
        }
        if(bn::keypad::up_pressed())
        {
            newleftshadowpos.set_y(newleftshadowpos.y() - 1);
            newrghtshadowpos.set_y(newrghtshadowpos.y() - 1);
            scrolly -= 1;
        }
        else if(bn::keypad::down_pressed())
        {
            newleftshadowpos.set_y(newleftshadowpos.y() + 1);
            newrghtshadowpos.set_y(newrghtshadowpos.y() + 1);
            scrolly += 1;
        }

        bn::regular_bg_map_cell plyr_map_cell1 = map_item.cell(newleftshadowpos);
        bn::regular_bg_map_cell plyr_map_cell2 = map_item.cell(newrghtshadowpos);
        int plyr_tile_index1 = bn::regular_bg_map_cell_info(plyr_map_cell1).tile_index();
        int plyr_tile_index2 = bn::regular_bg_map_cell_info(plyr_map_cell2).tile_index();

        bn::fixed plyr_sprite_x = (leftshadowpos.x() * 8) - (map_item.dimensions().width() * 4) + 4;
        bn::fixed plyr_sprite_y = (leftshadowpos.y() * 8) - (map_item.dimensions().height() * 4) + 4;
        plyr_left_shadow.set_position(plyr_sprite_x, plyr_sprite_y);
        plyr_rght_shadow.set_position(plyr_sprite_x + 8, plyr_sprite_y);

        if(plyr_tile_index1 == valid_tile_index && plyr_tile_index2 == valid_tile_index)
        {
        	camera.set_x(plyr_sprite_x + 4 + 0);
        	camera.set_y(plyr_sprite_y + 4 - 24);
            leftshadowpos = newleftshadowpos;
            rghtshadowpos = newrghtshadowpos;
        }

        // ----------------------------------------------------
		// Logging
		// ----------------------------------------------------
		if(bn::keypad::select_pressed()) { 
		    BN_LOG("===============");
		    BN_LOG("Back X: ",  scrollx);
		    BN_LOG("Back Y: ",  scrolly);
		    BN_LOG("plyr_sprite_x: ",  plyr_sprite_x);
		    BN_LOG("plyr_sprite_y: ",  plyr_sprite_y);
		}
		// ----------------------------------------------------
		// Type Text
		// ----------------------------------------------------
		const char c = conversation[sentence].at(letter);
        if(bn::keypad::b_pressed()) {
        	typetext = true;
        	bn::sound_items::short_square.play(0.25);
        	dialog.clear();
        	testing_text.clear();
        	letter = -1;
        	if(sentence < (int)sizeof(conversation)/8-1) sentence++;
        	if(sentence == sizeof(conversation)/8-1) sentence = 1;
        }
        if(typetext && testing_text.length() < conversation[sentence].length() + 1) {
        	dialog.clear();
        	if(letter < conversation[sentence].length() - 1) 
        	{
        		letter++;
        		if (letter % 3 == 0) bn::sound_items::short_square.play(0.5);
        	}
        	testing_text += c;
        	text_generator.generate(-110, -70, testing_text, dialog);
        }
        // ----------------------------------------------------
		bn::core::update();
    }
}

int main() {
    bn::core::init();
    bn::sprite_text_generator big_variable_text_generator(common::variable_8x16_sprite_font);
    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
    bn::bg_palettes::set_transparent_color(bn::color(5,5,5));
    //bn::music_items::ybacidrp.play(0.5);
    while(true) {
        test_scene(camera, big_variable_text_generator);
    }
    bn::core::update();
}