#include <stdio.h>
#include <time.h>
#include <mem.h>
#include "user.h"
#include "match.h"
#include "common.h"

int main() {

    time_t t;
    t = time(NULL);
    char *time=NULL;
//    fgets(time,20,stdin);
//    time_t mytime= toTimeStamp();
    printf("%d", sizeof(time_t));
    return 0;


    Match match={1,"Ìï¾¶",123456};
    insertOneMatch(match);
    match=__getLastMatch();
    printf("%d %s\n",match.id,match.matchName);
    printf("%d", sizeof(Match));



    return 0;
}