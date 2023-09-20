CasteliaCity_CafeSonataAlley_MapScripts::
	.byte 0


CasteliaCity_CafeSonataAlley_CafeSign::
	msgbox CasteliaCity_CafeSonataAlley_CafeSign_Text_0, MSGBOX_SIGN
	return


CasteliaCity_CafeSonataAlley_DirectionsSign::
	msgbox CasteliaCity_CafeSonataAlley_DirectionsSign_Text_0, MSGBOX_SIGN
	return


CasteliaCity_CafeSonataAlley_ShadyMan::
	msgbox CasteliaCity_CafeSonataAlley_ShadyMan_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	return


CasteliaCity_CafeSonataAlley_CafeSign_Text_0:
	.string "Café Sonata$"

CasteliaCity_CafeSonataAlley_DirectionsSign_Text_0:
	.string "{LEFT_ARROW} Liberty Pier\n"
	.string "Narrow Street {RIGHT_ARROW}$"

CasteliaCity_CafeSonataAlley_ShadyMan_Text_0:
	.string "Eheheheh...$"
