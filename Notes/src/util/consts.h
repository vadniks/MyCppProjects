/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_CONSTS_H
#define NOTES_CONSTS_H

#pragma once

//Defaults:
#define DEF_WIN_W                 350
#define DEF_WIN_H                 450
#define DEF_FONT_SIZE             14
#define APP_ICON_PATH             ":/resources/notes.png"

//Alerts:
#define ALERT_WIN_TITLE_WARNING   "Warning!"
#define ALERT_TEXT_EMPTY          "One of the text fields is empty!"
#define ALERT_ALRD_EXISTS         "This note already exists!"

//Exceptions:
#define ILLEGAL_STATE_EXCEPTION   "IllegalStateException"

//Main window:
#define MAIN_WIN_TITLE            "Notes"
#define MAIN_LIST_W               340
#define MAIN_LIST_H               448
#define MAIN_CREATE_BUTTON_TEXT   "Create note"

//Create window:
#define CREATE_WIN_TITLE          MAIN_CREATE_BUTTON_TEXT
#define CREATE_DONE_BUTTON_TEXT   "Done"
#define CREATE_CANCEL_BUTTON_TEXT "Cancel"
#define CREATE_TITLE_HINT         "Title"
#define CREATE_TEXT_HINT          "Text"

#endif //NOTES_CONSTS_H
