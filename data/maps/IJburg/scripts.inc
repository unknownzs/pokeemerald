IJburg_MapScripts::
	.byte 0

IJburg_EventScript_GardenSign::
	msgbox IJburg_Text_GardenSign, MSGBOX_SIGN
	end

IJburg_EventScript_FrenkiesHouseSign::
	msgbox IJburg_Text_FrenkiesHouseSign, MSGBOX_SIGN
	end

IJburg_EventScript_IJburgSign::
	msgbox IJburg_Text_IJburgSign, MSGBOX_SIGN
	end

IJburg_Text_FrenkiesHouseSign:
	.string "Frenkies House."
	.string "Give me rubbies, and enter!"


IJburg_Text_GardenSign:
	.string "Welcome to the Garden of IJburg. "
	.string "Only person's of extraordinary respect are allowed in."

IJburg_Text_IJburgSign:
	.string "IJburg"
	.string "Or Almere South South"