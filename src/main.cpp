// Kaputchip Advance by HusYada
#include "game.h"

void test_scene(bn::sprite_text_generator text_generator) {
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
	bn::regular_bg_ptr background_map = bn::regular_bg_items::test_map_2.create_bg(0,0);
	
	//bn::sprite_ptr plyr_current_tile = bn::sprite_items::cursor.create_sprite(0, 0);
	bn::sprite_ptr plyr_pixel = bn::sprite_items::cursor.create_sprite(0, 0);
	//bn::sprite_ptr plyr_tile_bound = bn::sprite_items::cursor.create_sprite(0, 0);
	bn::sprite_ptr plyr_next_tile = bn::sprite_items::cursor.create_sprite(0, 0);
	//plyr_current_tile.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(3));
	plyr_next_tile.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
	//plyr_tile_bound.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(1));

	const bn::regular_bg_map_item& map_item = bn::regular_bg_items::test_map_2.map_item();
    // bn::regular_bg_map_cell valid_map_cell1 = map_item.cell(0, 0);
    // bn::regular_bg_map_cell valid_map_cell2 = map_item.cell(0, 1);
    // bn::regular_bg_map_cell valid_map_cell3 = map_item.cell(0, 2);
    // int valid_tile_index1 = bn::regular_bg_map_cell_info(valid_map_cell1).tile_index();
    // int valid_tile_index2 = bn::regular_bg_map_cell_info(valid_map_cell2).tile_index();
    // int valid_tile_index3 = bn::regular_bg_map_cell_info(valid_map_cell3).tile_index();

    bn::point plyr_map_position(255, 255);

	// bool skipx = true;
	// bool skipy = true;

	while(true) {

		// Moving Map
		if(bn::keypad::a_held() && bn::keypad::left_held() && scrollx < 1928-4) {
			scrollx+=2;
		}
		if(bn::keypad::a_held() && bn::keypad::right_held() && scrollx > -3976) {
			scrollx-=2;
		}
		if(bn::keypad::a_held() && bn::keypad::up_held() && scrolly < 4016) {
			scrolly+=2;
		}
		if(bn::keypad::a_held() && bn::keypad::down_held() && scrolly > -4016) {
			scrolly-=2;
		}

		// if(bn::keypad::left_pressed() && scrollx < 1928) { scrollx+=1; }
		// if(bn::keypad::right_pressed() && scrollx > -3976) { scrollx-=1; }
		// if(bn::keypad::up_pressed() && scrolly < 4016) { scrolly+=1; }
		// if(bn::keypad::down_pressed() && scrolly > -4016) { scrolly-=1; }
        // if(bn::keypad::a_pressed()) { scene=25; }

		bn::fixed plyr_sprite_x = (plyr_map_position.x() * 8) - (map_item.dimensions().width() * 32) + 4;
        bn::fixed plyr_sprite_y = (plyr_map_position.y() * 8) - (map_item.dimensions().height() * 32) + 4;
        

        background_map.set_position(scrollx, scrolly);
        //plyr_next_tile.set_position(plyr_sprite_x + 8 * scrollx, plyr_sprite_y + 8 * scrolly);
        plyr_next_tile.set_position(plyr_sprite_x + 8 * scrollx, plyr_sprite_y + 8 * scrolly);

        // ----------------------------------------------------
		// Logging
		// ----------------------------------------------------
		if(bn::keypad::select_pressed()) { 
		    BN_LOG("===============");
		    // BN_LOG("Back X: ",  scrollx);
		    // BN_LOG("Back Y: ",  scrolly);
		    BN_LOG("---: ",  map_item.dimensions().width());
		    BN_LOG("---: ",  map_item.dimensions().width() * 32);
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
    bn::bg_palettes::set_transparent_color(bn::color(5,5,5));
    //bn::music_items::ybacidrp.play(0.5);
    while(true) {
        test_scene(big_variable_text_generator);
    }
    bn::core::update();
}