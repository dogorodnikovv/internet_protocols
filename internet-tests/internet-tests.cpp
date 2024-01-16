#include "pch.h"
#include "CppUnitTest.h"

#include "../internet_protocols/internet_structure.h"
#include "../internet_protocols/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace internettests
{
    internet_structure* build_protocol(int start_hour, int start_minute, int start_second, int end_hour, int end_minute, int end_second, std::string name) {
        internet_structure* protocol = new internet_structure;

        protocol->start_time.hour = start_hour;
        protocol->start_time.minute = start_minute;
        protocol->start_time.second = start_second;
        protocol->end_time.hour = end_hour;
        protocol->end_time.minute = end_minute;
        protocol->end_time.second = end_second;

        protocol->recieved = 0; 
        protocol->send = 0; 
        
		strncpy_s(protocol->program_name, name.c_str(), MAX_STRING_SIZE - 1);
        protocol->program_name[MAX_STRING_SIZE - 1] = '\0'; 

        return protocol;
    }

	void delete_protocol(internet_structure* array[], int size) {
		for (int i = 0; i < size; i++) {
			delete array[i];
		}
	}

	TEST_CLASS(internettests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			internet_structure* protocols[3];
			protocols[0] = build_protocol(12, 21, 11, 14, 21, 11, "Skype");
			protocols[1] = build_protocol(13, 21, 11, 16, 21, 11, "Skype");
			protocols[2] = build_protocol(14, 21, 11, 15, 21, 11, "Skype");
			internet_time longest_time = get_longest_time_program_name(protocols, 3, "Skype");
			std::string current_total_time = std::to_string(longest_time.hour) + ":" + std::to_string(longest_time.minute) + ":" + std::to_string(longest_time.second);
			std::string expected_time = "6:0:0";
			Assert::AreEqual(expected_time, current_total_time);
			delete_protocol(protocols, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			internet_structure* protocols[3];
			protocols[0] = build_protocol(12, 21, 11, 12, 21, 12, "Skype");
			protocols[1] = build_protocol(13, 21, 11, 13, 21, 12, "Skype");
			protocols[2] = build_protocol(14, 21, 11, 14, 21, 12, "Skype");
			internet_time longest_time = get_longest_time_program_name(protocols, 3, "Skype");
			std::string current_total_time = std::to_string(longest_time.hour) + ":" + std::to_string(longest_time.minute) + ":" + std::to_string(longest_time.second);
			std::string expected_time = "0:0:3";
			Assert::AreEqual(expected_time, current_total_time);
			delete_protocol(protocols, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			internet_structure* protocols[3];
			protocols[0] = build_protocol(12, 21, 11, 12, 22, 11, "Skype");
			protocols[1] = build_protocol(13, 21, 11, 13, 22, 11, "Skype");
			protocols[2] = build_protocol(14, 21, 11, 14, 22, 11, "Skype");
			internet_time longest_time = get_longest_time_program_name(protocols, 3, "Skype");
			std::string current_total_time = std::to_string(longest_time.hour) + ":" + std::to_string(longest_time.minute) + ":" + std::to_string(longest_time.second);
			std::string expected_time = "0:3:0";
			Assert::AreEqual(expected_time, current_total_time);
			delete_protocol(protocols, 3);
		}
	};
}
