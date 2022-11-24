//
// Created by flo47663 on 23.11.2022.
//

#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>



/********************************
*adjust the path to the src_generated directory
********************************/
#include "../cmake-build-debug/src_generated/namespace_temperature_generated.h"

#include "../cmake-build-debug/src_generated/types_temperature_generated.h"
#include "../cmake-build-debug/src_generated/types_temperature_generated_handling.h"

/******************
*Add the Set_Temperature Callback function here
******************/



UA_Boolean running = true;

static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "received ctrl-c");
    running = false;
}

int main(int argc, char** argv) {
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    UA_Server *server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));

    /* create nodes from nodeset */
    UA_StatusCode retval = namespace_temperature_generated(server);


    if(retval != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Adding the temperature namespace failed. Please check previous error output.");
        UA_Server_delete(server);
        return EXIT_FAILURE;
    }
    /********************************
	*insert the declare object template
	*******************************/
    



	/********************************
	*insert the write custom variable template here
	*******************************/



    
	/************************************************
	*add the link method callback here
	************************************************/
	


    retval = UA_Server_run(server, &running);

    UA_Server_delete(server);
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}