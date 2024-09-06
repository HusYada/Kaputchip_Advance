// Kaputchip Advance by HusYada
#include "game.h"

void test_scene(bn::camera_ptr& camera, bn::sprite_text_generator text_generator) {
	// -------------------------------------------------------------------------------------------------------
	// Text Stuff
	// -------------------------------------------------------------------------------------------------------
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
    // -------------------------------------------------------------------------------------------------------
    // Sprites & Background Map Stuff
    // -------------------------------------------------------------------------------------------------------
	bn::regular_bg_ptr background_map = bn::regular_bg_items::test_map_2.create_bg(0,0);
    bn::sprite_ptr plyr_tile_bound = bn::sprite_items::cursor.create_sprite(0, 0);
    plyr_tile_bound.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(1));
	bn::sprite_ptr plyr_left_shadow = bn::sprite_items::cursor.create_sprite(0, 0);
    bn::sprite_ptr plyr_rght_shadow = bn::sprite_items::cursor.create_sprite(0, 0);
	plyr_left_shadow.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
    plyr_rght_shadow.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
    bn::sprite_ptr plyr_pixel = bn::sprite_items::cursor.create_sprite(0, 0);

    // Player
    bn::sprite_ptr plyr_s = bn::sprite_items::p_shadow.create_sprite(0, 24);
    bn::sprite_ptr plyr_r = bn::sprite_items::rarm.create_sprite(-16, 8);
    bn::sprite_ptr plyr_l = bn::sprite_items::big_heart.create_sprite(16, 8);
    bn::sprite_ptr plyr_d = bn::sprite_items::legs.create_sprite(0, 16);
    bn::sprite_ptr plyr_b = bn::sprite_items::body.create_sprite(0, 0);

    // Player
    bn::sprite_ptr enm1 = bn::sprite_items::e_bug.create_sprite(0, 0);

	const bn::regular_bg_map_item& map_item = bn::regular_bg_items::test_map_2.map_item();
    bn::regular_bg_map_cell valid_map_cells[3] = {
    map_item.cell(0, 0), map_item.cell(0, 1), map_item.cell(0, 2)
    };
    int valid_map_cells_length = sizeof(valid_map_cells)/sizeof(bn::regular_bg_map_cell);

    bn::point leftshadowpos(255, 255);
    bn::point rghtshadowpos(256, 255);
    background_map.set_camera(camera);
    plyr_left_shadow.set_camera(camera);
    plyr_rght_shadow.set_camera(camera);

    bn::point enemtarget(259, 255);

    // -------------------------------------------------------------------------------------------------------
	while(true)
    {
    	bn::point newleftshadowpos = leftshadowpos;
        bn::point newrghtshadowpos = rghtshadowpos;

        if(bn::keypad::a_held())
        {
            speed = 2;
        }
        if(bn::keypad::a_released())
        {
            speed = 1;
        }

        //-4, -5
        // 4,  5

        // -------------------------------------------------------------------------------------------------------
        // Movement
        // -------------------------------------------------------------------------------------------------------
        if(bn::keypad::left_held()){
        //|| (bn::keypad::a_held() && newleftshadowpos.x() > enemtarget.x())) {
            scrollx -= speed;
            direction = 2;
            leftorright = false;

            plyr_b.set_tiles(bn::sprite_items::body.tiles_item().create_tiles(2));
            walking = true;
            plyr_r.set_horizontal_flip(false);
            plyr_b.set_horizontal_flip(false);
            plyr_d.set_horizontal_flip(false);

            if(scrollx < -4 / speed)
            {
                //scrollx = 0;
                newleftshadowpos.set_x(newleftshadowpos.x() - 1);
                newrghtshadowpos.set_x(newrghtshadowpos.x() - 1);
                if(scrollx < -5)
                {
                    scrollx = 0;
                    newleftshadowpos.set_x(newleftshadowpos.x() + 1);
                    newrghtshadowpos.set_x(newrghtshadowpos.x() + 1);
                }
            }
        }
        else if(bn::keypad::right_held()){
        //|| (bn::keypad::a_held() && newrghtshadowpos.x() < enemtarget.x())) {
            scrollx += speed;
            direction = 2;
            leftorright = true;

            plyr_b.set_tiles(bn::sprite_items::body.tiles_item().create_tiles(2));
            walking = true;
            plyr_r.set_horizontal_flip(true);
            plyr_b.set_horizontal_flip(true);
            plyr_d.set_horizontal_flip(true);

            if(scrollx > 4 / speed)
            {
                //scrollx = 0;
                newleftshadowpos.set_x(newleftshadowpos.x() + 1);
                newrghtshadowpos.set_x(newrghtshadowpos.x() + 1);
                if(scrollx > 5)
                {
                    scrollx = 0;
                    newleftshadowpos.set_x(newleftshadowpos.x() - 1);
                    newrghtshadowpos.set_x(newrghtshadowpos.x() - 1);
                }
            }
        }
        if(bn::keypad::up_held()){
        //|| (bn::keypad::a_held() && newrghtshadowpos.y() > enemtarget.y())) {

            scrolly -= speed;
            direction = 4;
            walking = true;

            plyr_b.set_tiles(bn::sprite_items::body.tiles_item().create_tiles(4));
            plyr_d.set_tiles(bn::sprite_items::legs.tiles_item().create_tiles(4));

            if(scrolly < -4 / speed)
            {
                //scrolly = 0;
                newleftshadowpos.set_y(newleftshadowpos.y() - 1);
                newrghtshadowpos.set_y(newrghtshadowpos.y() - 1);
                if(scrolly < -5)
                {
                    scrolly = 0;
                    newleftshadowpos.set_y(newleftshadowpos.y() + 1);
                    newrghtshadowpos.set_y(newrghtshadowpos.y() + 1);
                }
            }
        }
        else if(bn::keypad::down_held()){
        //|| (bn::keypad::a_held() && newrghtshadowpos.y() < enemtarget.y())) {

            scrolly += speed;
            direction = 0;
            walking = true;

            plyr_b.set_tiles(bn::sprite_items::body.tiles_item().create_tiles(0));
            plyr_d.set_tiles(bn::sprite_items::legs.tiles_item().create_tiles(0));

            if(scrolly > 4 / speed)
            {
                //scrolly = 0;
                newleftshadowpos.set_y(newleftshadowpos.y() + 1);
                newrghtshadowpos.set_y(newrghtshadowpos.y() + 1);  
                if(scrolly > 5)
                {
                    scrolly = 0;
                    newleftshadowpos.set_y(newleftshadowpos.y() - 1);
                    newrghtshadowpos.set_y(newrghtshadowpos.y() - 1);
                }
            }
        }
        // -------------------------------------------------------------------------------------------------------
        // Riichi
        // -------------------------------------------------------------------------------------------------------
        if(bn::keypad::r_pressed() && !r_attack && !r_return && (rarmx == -16 || rarmx == 32)) {
            r_attack = true;
            if(leftorright) atk_dirx = 1;
            if(!leftorright) atk_dirx = -1;
            if(direction == 0) atk_diry = 1;
            if(direction == 2) atk_diry = 0;
            if(direction == 4) atk_diry = -1;
            plyr_r.set_tiles(bn::sprite_items::rarm.tiles_item().create_tiles(1));
        }
        if(r_attack && !r_return)
        {
            rarmx += atk_dirx * 4;
            rarmy += atk_diry * 4;
            plyr_r.set_horizontal_flip(leftorright);

            if((atk_dirx == -1 && rarmx < -46) || (atk_dirx == 1 && rarmx > 62))
            {
                plyr_r.set_tiles(bn::sprite_items::rarm.tiles_item().create_tiles(2));
                r_attack = false;
                r_return = true;
            }
        }
        if(r_return && !r_attack)
        {
            if(atk_dirx == -1) rarmx -= atk_dirx * 8;
            if(atk_dirx == 1)  rarmx -= atk_dirx * 8;
            if(leftorright && rarmx < 32) rarmx += atk_dirx * 8;
            if(rarmy < 6) rarmy += 4;
            if(rarmy > 10) rarmy -= 4;
            if(rarmx <= 32 && rarmx >= -16 && rarmy >= 6 && rarmy <= 10) r_return = false;
        }
        if(!r_return && !r_attack)
        {
            plyr_r.set_tiles(bn::sprite_items::rarm.tiles_item().create_tiles(0));
            if(!leftorright && rarmx > -16) rarmx -= 8;
            if(leftorright && rarmx < 32) rarmx += 8;
        }
        // Heart
        if(!l_return && !l_attack)
        {
            if(!leftorright && larmx < 16) larmx += 8;
            if(leftorright && larmx > -28) larmx -= 8;
        }
        // Walk Cycle
        if(walking)
        {
            if(pa<2) { paa++;}
            if(paa>10/speed) { pa++; paa=0;}
            if(pa==1 && paa > 3){ pa=0;}
            plyr_d.set_tiles(bn::sprite_items::legs.tiles_item().create_tiles(pa+direction));
            if(bn::keypad::left_released() || bn::keypad::right_released()
            || bn::keypad::up_released() || bn::keypad::down_released())
            {
                walking = false;
                plyr_d.set_tiles(bn::sprite_items::legs.tiles_item().create_tiles(direction));
            }
        }
        plyr_l.set_position(larmx + 8, larmy);
        plyr_r.set_position(rarmx - 8, rarmy);

        // -------------------------------------------------------------------------------------------------------
        // Main Tile Collision
        // -------------------------------------------------------------------------------------------------------
        bn::regular_bg_map_cell plyr_map_cell1 = map_item.cell(newleftshadowpos);
        bn::regular_bg_map_cell plyr_map_cell2 = map_item.cell(newrghtshadowpos);
        int plyr_tile_index1 = bn::regular_bg_map_cell_info(plyr_map_cell1).tile_index();
        int plyr_tile_index2 = bn::regular_bg_map_cell_info(plyr_map_cell2).tile_index();

        bn::fixed plyr_sprite_x = (leftshadowpos.x() * 8) - (map_item.dimensions().width() * 4) + 4;
        bn::fixed plyr_sprite_y = (leftshadowpos.y() * 8) - (map_item.dimensions().height() * 4) + 4;
        plyr_left_shadow.set_position(plyr_sprite_x, plyr_sprite_y);
        plyr_rght_shadow.set_position(plyr_sprite_x + 8, plyr_sprite_y);

        plyr_pixel.set_position(scrollx, scrolly);
        camera.set_x(plyr_sprite_x + scrollx + 4);
        camera.set_y(plyr_sprite_y + scrolly - 28);

        for(int i = 0; i < valid_map_cells_length; i++)
        {
            for(int j = 0; j < valid_map_cells_length; j++)
            {
                if(plyr_tile_index1 == bn::regular_bg_map_cell_info(valid_map_cells[i]).tile_index()
                && plyr_tile_index2 == bn::regular_bg_map_cell_info(valid_map_cells[j]).tile_index())
                {
                    leftshadowpos = newleftshadowpos;
                    rghtshadowpos = newrghtshadowpos;
                }
            }
        }

        // -------------------------------------------------------------------------------------------------------
        // Enemies
        // -------------------------------------------------------------------------------------------------------
        enm1.set_position(plyr_sprite_x + scrollx + 4 + ex1, plyr_sprite_y + scrolly + 4 + ey1);

        // -------------------------------------------------------------------------------------------------------
		// Logging
		// -------------------------------------------------------------------------------------------------------
		if(bn::keypad::select_pressed()) { 
            rarmx = -16;
            rarmy = 0;
		    BN_LOG("===============");
		    // BN_LOG("Back X: ",  scrollx);
		    // BN_LOG("Back Y: ",  sizeof(bn::regular_bg_map_cell));
		    // BN_LOG("plyr_sprite_x: ",  plyr_sprite_x);
		    // BN_LOG("plyr_sprite_y: ",  plyr_sprite_y);
            BN_LOG("RATKx: ",  rarmx);
            BN_LOG("RATKy: ",  rarmy);
		}
		// -------------------------------------------------------------------------------------------------------
		// Type Text
		// -------------------------------------------------------------------------------------------------------
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
        // -------------------------------------------------------------------------------------------------------
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