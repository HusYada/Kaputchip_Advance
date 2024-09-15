// Kaputchip Advance by HusYada
#ifndef PLAYER_H
#define PLAYER_H

// Inlcude
#include "bn_sprite_ptr.h"
// Sprites
#include "bn_sprite_items_body.h"
#include "bn_sprite_items_bubble.h"

class player {
	private:
		int bruh;
		//bn::sprite_ptr plyr_bub = bn::sprite_items::body.create_sprite(40, 40);
		//bn::sprite_ptr plyr_bub;
	public:
		void start();
		void update();
};

#endif