#ifndef UIPROVIDER_H
#define UIPROVIDER_H
#include "state.h"
#include "map"

//user actions
enum UserAction
{
    ACTION_UNKNOWN=-1,
    ACTION_HELP=0,
    ACTION_QSTORE,
    ACTION_QRETRIEVE,
    ACTION_GET,
    ACTION_PRINT,
    ACTION_QUIT
};

//State class fields
enum
{
    FIELD_COUNTRY_NAME=1,
    FIELD_CAPITAL_NAME,
    FIELD_LANGUAGE,
    FIELD_POPULATION,
    FIELD_AREA,
    FIELD_UNIT,
    FIELD_SYSTEM
};

static std::map <char, UserAction> Commands{{'h',ACTION_HELP}, {'s',ACTION_QSTORE},{'r',ACTION_QRETRIEVE},
                                            {'g',ACTION_GET},{'p',ACTION_PRINT},{'q',ACTION_QUIT}};
class UIProvider
{

   static UserAction getAction(char s);

   static void clearStream();

   static void handleHelp();
   static void handleStoreAction( Queue<State>&queue);
   static void handleRetrieveAction( Queue<State>&queue);
   static void handleGetAction( Queue<State>&queue);
   static void handlePrintAction( Queue<State>&queue);
   static void handleReadAction(Queue<State>& queue);

public:

   static void handleUserInput(Queue<State>&queue);

};

#endif // UIPROVIDER_H
