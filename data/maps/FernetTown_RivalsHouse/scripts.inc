FernetTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FernetTown_RivalsHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FernetTown_RivalsHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FERNET_RIVAL_HOUSE_STATE, 0, FernetTown_RivalsHouse_StarterPick
	.2byte 0


FernetTown_RivalsHouse_StarterPick::
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, FernetTown_RivalsHouse_TownElder_Movement1
	waitmovement 0
	msgbox FernetTown_RivalsHouse_StarterPick_Text_0
	applymovement 1, FernetTown_RivalsHouse_TownElder_Movement2
	applymovement OBJ_EVENT_ID_PLAYER, FernetTown_RivalsHouse_Player_Movement
	waitmovement 0
	faceplayer
	msgbox FernetTown_RivalsHouse_StarterPick_Text_1
	setvar VAR_FERNET_RIVAL_HOUSE_STATE, 1
	setvar VAR_FERNET_TOWN_ELDER, 1
	releaseall
	end


FernetTown_RivalsHouse_TownElder::
	lock
	faceplayer
	switch VAR_FERNET_TOWN_ELDER
	case 0, FernetTown_RivalsHouse_TownElder_3
	case 1, FernetTown_RivalsHouse_TownElder_4
	case 2, FernetTown_RivalsHouse_TownElder_5
	msgbox FernetTown_RivalsHouse_TownElder_Text_4
FernetTown_RivalsHouse_TownElder_1:
	release
	end

FernetTown_RivalsHouse_TownElder_3:
	goto_if_set FLAG_SYS_POKEMON_GET, FernetTown_RivalsHouse_TownElder_7
	msgbox FernetTown_RivalsHouse_TownElder_Text_1
	goto FernetTown_RivalsHouse_TownElder_1

FernetTown_RivalsHouse_TownElder_4:
	msgbox FernetTown_RivalsHouse_TownElder_Text_2
	goto FernetTown_RivalsHouse_TownElder_1

FernetTown_RivalsHouse_TownElder_5:
	msgbox FernetTown_RivalsHouse_TownElder_Text_3
	goto FernetTown_RivalsHouse_TownElder_1

FernetTown_RivalsHouse_TownElder_7:
	msgbox FernetTown_RivalsHouse_TownElder_Text_0
	goto FernetTown_RivalsHouse_TownElder_1


FernetTown_RivalsHouse_Treecko::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, FernetTown_RivalsHouse_Treecko_2
	msgbox FernetTown_RivalsHouse_Treecko_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FernetTown_RivalsHouse_Treecko_5
	givemon SPECIES_TREECKO, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq FernetTown_RivalsHouse_Treecko_9
	compare VAR_RESULT, 1
	goto_if_eq FernetTown_RivalsHouse_Treecko_10
	goto Common_EventScript_NoMoreRoomForPokemon
FernetTown_RivalsHouse_Treecko_8:
	goto FernetTown_RivalsHouse_ChosenStarter
FernetTown_RivalsHouse_Treecko_1:
	release
	end

FernetTown_RivalsHouse_Treecko_2:
	msgbox FernetTown_RivalsHouse_Treecko_Text_0
	goto FernetTown_RivalsHouse_Treecko_1

FernetTown_RivalsHouse_Treecko_5:
	goto FernetTown_RivalsHouse_Treecko_1

FernetTown_RivalsHouse_Treecko_9:
	call FernetTown_RivalsHouse_Fanfare_Treecko
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Treecko_15
FernetTown_RivalsHouse_Treecko_14:
	closemessage
	goto FernetTown_RivalsHouse_Treecko_8

FernetTown_RivalsHouse_Treecko_10:
	call FernetTown_RivalsHouse_Fanfare_Treecko
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Treecko_18
FernetTown_RivalsHouse_Treecko_17:
	call Common_EventScript_TransferredToPC
	goto FernetTown_RivalsHouse_Treecko_8

FernetTown_RivalsHouse_Treecko_15:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Treecko_14

FernetTown_RivalsHouse_Treecko_18:
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Treecko_17


FernetTown_RivalsHouse_Torchic::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, FernetTown_RivalsHouse_Torchic_2
	msgbox FernetTown_RivalsHouse_Torchic_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FernetTown_RivalsHouse_Torchic_5
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq FernetTown_RivalsHouse_Torchic_9
	compare VAR_RESULT, 1
	goto_if_eq FernetTown_RivalsHouse_Torchic_10
	goto Common_EventScript_NoMoreRoomForPokemon
FernetTown_RivalsHouse_Torchic_8:
	goto FernetTown_RivalsHouse_ChosenStarter
FernetTown_RivalsHouse_Torchic_1:
	release
	end

FernetTown_RivalsHouse_Torchic_2:
	msgbox FernetTown_RivalsHouse_Treecko_Text_0
	goto FernetTown_RivalsHouse_Torchic_1

FernetTown_RivalsHouse_Torchic_5:
	goto FernetTown_RivalsHouse_Torchic_1

FernetTown_RivalsHouse_Torchic_9:
	call FernetTown_RivalsHouse_Fanfare_Torchic
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Torchic_15
FernetTown_RivalsHouse_Torchic_14:
	closemessage
	goto FernetTown_RivalsHouse_Torchic_8

FernetTown_RivalsHouse_Torchic_10:
	call FernetTown_RivalsHouse_Fanfare_Torchic
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Torchic_18
FernetTown_RivalsHouse_Torchic_17:
	call Common_EventScript_TransferredToPC
	goto FernetTown_RivalsHouse_Torchic_8

FernetTown_RivalsHouse_Torchic_15:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Torchic_14

FernetTown_RivalsHouse_Torchic_18:
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Torchic_17


FernetTown_RivalsHouse_Mudkip::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, FernetTown_RivalsHouse_Mudkip_2
	msgbox FernetTown_RivalsHouse_Mudkip_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FernetTown_RivalsHouse_Mudkip_5
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq FernetTown_RivalsHouse_Mudkip_9
	compare VAR_RESULT, 1
	goto_if_eq FernetTown_RivalsHouse_Mudkip_10
	goto Common_EventScript_NoMoreRoomForPokemon
FernetTown_RivalsHouse_Mudkip_8:
	goto FernetTown_RivalsHouse_ChosenStarter
FernetTown_RivalsHouse_Mudkip_1:
	release
	end

FernetTown_RivalsHouse_Mudkip_2:
	msgbox FernetTown_RivalsHouse_Treecko_Text_0
	goto FernetTown_RivalsHouse_Mudkip_1

FernetTown_RivalsHouse_Mudkip_5:
	goto FernetTown_RivalsHouse_Mudkip_1

FernetTown_RivalsHouse_Mudkip_9:
	call FernetTown_RivalsHouse_Fanfare_Mudkip
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Mudkip_15
FernetTown_RivalsHouse_Mudkip_14:
	closemessage
	goto FernetTown_RivalsHouse_Mudkip_8

FernetTown_RivalsHouse_Mudkip_10:
	call FernetTown_RivalsHouse_Fanfare_Mudkip
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_Mudkip_18
FernetTown_RivalsHouse_Mudkip_17:
	call Common_EventScript_TransferredToPC
	goto FernetTown_RivalsHouse_Mudkip_8

FernetTown_RivalsHouse_Mudkip_15:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Mudkip_14

FernetTown_RivalsHouse_Mudkip_18:
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_Mudkip_17


FernetTown_RivalsHouse_Fanfare_Treecko::
	bufferspeciesname 1, SPECIES_TREECKO
	removeobject 2
	playfanfare MUS_EVOLVED
	setflag FLAG_SYS_POKEMON_GET
	message FernetTown_RivalsHouse_Fanfare_Treecko_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TREECKO
	return


FernetTown_RivalsHouse_Fanfare_Torchic::
	bufferspeciesname 1, SPECIES_TORCHIC
	removeobject 3
	playfanfare MUS_EVOLVED
	setflag FLAG_SYS_POKEMON_GET
	message FernetTown_RivalsHouse_Fanfare_Torchic_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TORCHIC
	return


FernetTown_RivalsHouse_Fanfare_Mudkip::
	bufferspeciesname 1, SPECIES_MUDKIP
	removeobject 4
	playfanfare MUS_EVOLVED
	setflag FLAG_SYS_POKEMON_GET
	message FernetTown_RivalsHouse_Fanfare_Mudkip_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MUDKIP
	return


FernetTown_RivalsHouse_ChosenStarter::
	setvar VAR_FERNET_RIVAL_HOUSE_STATE, 2
	setflag FLAG_HIDE_FERNET_TOWN_TREECKO
	setflag FLAG_HIDE_FERNET_TOWN_TORCHIC
	setflag FLAG_HIDE_FERNET_TOWN_MUDKIP
	end


FernetTown_RivalsHouse_PreventExitSouth::
	lockall
	msgbox FernetTown_RivalsHouse_PreventExitSouth_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FernetTown_RivalsHouse_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end


FernetTown_RivalsHouse_PreventExitEast::
	lockall
	msgbox FernetTown_RivalsHouse_PreventExitSouth_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FernetTown_RivalsHouse_Movement_PreventExitEast
	waitmovement 0
	releaseall
	end


FernetTown_RivalsHouse_Movement_PreventExitEast:
	walk_left
	step_end

FernetTown_RivalsHouse_Movement_PreventExitSouth:
	walk_up
	step_end

FernetTown_RivalsHouse_TownElder_Movement1:
	walk_right
	walk_down
	walk_down
	step_end

FernetTown_RivalsHouse_TownElder_Movement2:
	walk_up
	walk_up
	walk_left
	step_end

FernetTown_RivalsHouse_Player_Movement:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

FernetTown_RivalsHouse_StarterPick_Text_0:
	.string "Ah, {PLAYER}! \nI was expecting you. \pCome over here and choose \nyourself a POKéMON.$"

FernetTown_RivalsHouse_StarterPick_Text_1:
	.string "Choose one of these!$"

FernetTown_RivalsHouse_TownElder_Text_0:
	.string "Go out and explore the world!$"

FernetTown_RivalsHouse_TownElder_Text_1:
	.string "Please choose your prefered POKéMON.$"

FernetTown_RivalsHouse_TownElder_Text_2:
	.string "I heard you beat my grandson in battle!$"

FernetTown_RivalsHouse_TownElder_Text_3:
	.string "...\n"
	.string "...\l"
	.string "...\p"
	.string "I farted$"

FernetTown_RivalsHouse_TownElder_Text_4:
	.string "It is time to explore the world!$"

FernetTown_RivalsHouse_Treecko_Text_0:
	.string "You already got one POKéMON. Don't be\n"
	.string "greedy!$"

FernetTown_RivalsHouse_Treecko_Text_1:
	.string "Take the POKéMON TREECKO?$"

FernetTown_RivalsHouse_Torchic_Text_0:
	.string "Take the POKéMON TORCHIC?$"

FernetTown_RivalsHouse_Mudkip_Text_0:
	.string "Take the POKéMON MUDKIP?$"

FernetTown_RivalsHouse_Fanfare_Treecko_Text_0:
	.string "{PLAYER} obtained TREECKO!$"

FernetTown_RivalsHouse_Fanfare_Torchic_Text_0:
	.string "{PLAYER} obtained TORCHIC!$"

FernetTown_RivalsHouse_Fanfare_Mudkip_Text_0:
	.string "{PLAYER} obtained MUDKIP!$"

FernetTown_RivalsHouse_PreventExitSouth_Text_0:
	.string "Choose a POKéMON before you leave.$"
