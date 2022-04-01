Route122_MapScripts::
	.byte 0


Route122_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, Route122_OldRodFisherman_2
	msgbox Route122_OldRodFisherman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route122_OldRodFisherman_5
	msgbox Route122_OldRodFisherman_Text_4
Route122_OldRodFisherman_1:
	release
	end

Route122_OldRodFisherman_2:
	msgbox Route122_OldRodFisherman_Text_0
	goto Route122_OldRodFisherman_1

Route122_OldRodFisherman_5:
	msgbox Route122_OldRodFisherman_Text_2
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox Route122_OldRodFisherman_Text_3
	goto Route122_OldRodFisherman_1


Route122_Worker1::
	lock
	faceplayer
	msgbox Route122_Worker1_Text_0
	release
	end


Route122_Worker2::
	lock
	faceplayer
	msgbox Route122_Worker2_Text_0
	release
	end


Route122_Worker3::
	lock
	faceplayer
	msgbox Route122_Worker3_Text_0
	release
	end


Route122_OldRodFisherman_Text_0:
	.string "The sea is wonderful, don't you think?$"

Route122_OldRodFisherman_Text_1:
	.string "The sea brings so many a joy. Like\n"
	.string "fishing! Would you like to experience\l"
	.string "the joy of fishing?$"

Route122_OldRodFisherman_Text_2:
	.string "Then take this!$"

Route122_OldRodFisherman_Text_3:
	.string "It's not top notch, but it will do the\n"
	.string "trick.$"

Route122_OldRodFisherman_Text_4:
	.string "What a joyless existence...$"

Route122_Worker1_Text_0:
	.string "The boss is strict, but fair!$"

Route122_Worker2_Text_0:
	.string "The construction of the road to\n"
	.string "LILYCOVE is almost finished.$"

Route122_Worker3_Text_0:
	.string "I am sorry, due to security reasons no\n"
	.string "one is allowed on the PYRE PROMENADE\l"
	.string "yet.$"
