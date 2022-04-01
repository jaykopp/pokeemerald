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
