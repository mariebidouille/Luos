// Always include this file
#include "../test/unit_test.h"

// Example template function to test
#include "template.h"

// Include the needed file(s) which contains the function(s) you have to test and the dependencies :
#include "../inc/luos.h"
#include "../inc/streaming.h"

/* -------------------------------------------*/
/* TEMPLATE UNIT TEST EXAMPLE (TO BE DELETED) */
/* -------------------------------------------*/
void unittest_Template()
{
    NEW_TEST_CASE("Verify my function returns 1 when input is 0"); // Explain here your 1st test case
    {
        // Init variables
        //---------------
        uint32_t input           = 0;
        uint32_t output          = 0;
        uint32_t expected_output = 1;

        // Call function
        //---------------------------
        NEW_STEP("Check output is 1"); // Explain here your first test case
        output = fake_function_to_test(input);

        // Verify
        // (All platformio asserts functions are details here : https://docs.platformio.org/en/latest/plus/unit-testing.html#api)
        //--------------------------------------------------------------------
        TEST_ASSERT_EQUAL(expected_output, output);

        // Call function
        //---------------------------
        NEW_STEP("Check output is 2"); // Explain here your first test case
        output = fake_function_to_test(input);

        // Verify
        //--------------------------------------------------------------------
        //TEST_ASSERT_EQUAL(10, output); // These step will fail because 1 is not equal to 10 !
    }

    NEW_TEST_CASE("Verify my function do something else"); // Explain here your 2nd test case
    {
        // Init variables
        //---------------
        uint32_t expected_output = 1;

        // Call function and verify
        //---------------------------
        for (uint8_t i = 0; i < 8; i++)
        {
            NEW_STEP_IN_LOOP("Do a check in a loop", i);
            TEST_ASSERT_EQUAL(expected_output, fake_function_to_test(i));
            expected_output++;
        }
    }
}

/* ---------------------------*/
/* YOUR UNIT TEST START HERE  */
/* ---------------------------*/
void unittest_Streaming_SendStreamingSize()
{
    NEW_TEST_CASE("TODO");
    {
        // Init variables
        //---------------
        msg_t msg;
        service_t service;
        streaming_channel_t stream;
        uint32_t max_size;

        // Init context
        //---------------

        // TODO
        max_size = 1;

        // TODO
        msg.header.target_mode = 1;
        msg.header.target      = 2;
        msg.header.cmd         = 3;
        msg.header.size        = 1;
        msg.data[0]            = 0x0A;

        // VARIABLE des scénars :
        //  - max_size
        //  - msg->data
        //  - stream->data_size
        //  - Luos_SendMsg doit être SUCCESS

        // TODO
        /*
        service->ll_service = x;
        service->x;                                // Callback    void (*service_cb)(struct service_t * service, msg_t * msg)
        service.default_alias[MAX_ALIAS_SIZE] = x; //  service default alias.
        service.alias[MAX_ALIAS_SIZE]         = x; //  service alias.
        service.auto_refresh                  = x; //  service auto refresh context.
        service.revision                      = x; //  service firmware version.
        service->node_statistics              = x; //  Node level statistics.
        service.statistics                    = x; //  service level statistics.
        service.access                        = x; //  service read write access.
        service->profile_context              = x; //  Pointer to the profile context.
        */

        // TODO
        /*
        stream->ring_buffer     = x; // Begin ring buffer pointer
        stream->end_ring_buffer = x; // End of the ring buffer
        stream->sample_ptr      = x; // Current sample pointer (pointer always point a fresh data)
        stream->data_ptr        = x; // Current pointer of data
        stream.data_size        = x; // Size granulariry of the data contained on the ring buffer
        */

        // Dependances :
        // Stream_GetAvailableSampleNB
        // return        nb_available_sample = ((stream->end_ring_buffer - stream->sample_ptr) + (stream->data_ptr - stream->ring_buffer)) / stream->data_size;
        // Stream_GetSample

        //--------------------------------------------------------------------
        // Call function
        //--------------------------------------------------------------------
        NEW_STEP("TO FILL");
        //SendStreamingSize(&service, &msg, &stream, max_size);

        //--------------------------------------------------------------------
        // Verify
        //--------------------------------------------------------------------
        //TEST_ASSERT_EQUAL(exepected_value, measured_value);

        // Check data_size
        // Check msg_number
        // Check chunk_size
    }
}

/*******************************************************************************
 * MAIN
 ******************************************************************************/
int main(int argc, char **argv)
{
    UNITY_BEGIN();

    //To launch this test :
    //   1)   go to Luos directory (you should see "platformio.ini" file in this directory)
    //   2)   platformio test -e native -i CodeCoverage --verbose -f streaming"
    UNIT_TEST_RUN(unittest_Template);                    // Template unit test function (TO BE DELETED)
    UNIT_TEST_RUN(unittest_Streaming_SendStreamingSize); // ---> Montrer DEBUG ds platformio.ini !!!!!!!
    UNITY_END();
}
