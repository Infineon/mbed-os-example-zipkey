/*
 * Copyright (C) 2019, Cirrent Inc
 *
 * All use of this software must be covered by a license agreement as described in
 * Cirrent Terms of Services (https://www.cirrent.com/terms-of-service/)
 *
 * DISCLAIMER. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OR CONDITION,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. LICENSORS HEREBY DISCLAIM
 * ALL LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE.
 */

#if !MBED_TEST_MODE
#include "mbed.h"
#include "cirrent.h"
#include "ca_config_data.h"

DigitalOut led1(LED1);

#if defined(MBED_MEM_TRACING_ENABLED) && defined(MBED_HEAP_STATS_ENABLED) && defined(MBED_STACK_STATS_ENABLED)
#define CA_MBED_PRINT_STATS
#endif

#ifdef CA_MBED_PRINT_STATS

void print_memory_stats() {
    // allocate enough room for every thread's stack statistics
    int cnt = osThreadGetCount();
    mbed_stats_stack_t *stats = (mbed_stats_stack_t*) malloc(cnt * sizeof(mbed_stats_stack_t));

    cnt = mbed_stats_stack_get_each(stats, cnt);
    for (int i = 0; i < cnt; i++) {
        printf("Thread: 0x%lX, Stack size: %lu / %lu\r\n", stats[i].thread_id, stats[i].max_size, stats[i].reserved_size);
    }
    free(stats);

    // Grab the heap statistics
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    printf("Heap size: %lu / %lu bytes\r\n", heap_stats.current_size, heap_stats.reserved_size);
}

#endif // CA_MBED_PRINT_STATS


// main() runs in its own thread in the OS
int main()
{
    led1 = !led1;
    printf("\n ZipKey Example App\r\n\n");
    CA_INIT_CONFIG_T ca_init_config;
    CA_RESULT_T res;

    ca_init_config.user_binding_enabled = true;
    ca_init_config.onboarding_button_exists = true;
    ca_init_config.log_print_enabled = true;

    ca_init_config.softap_config.softap_enabled = false;
    ca_init_config.softap_config.server_port = 80;
    strcpy(ca_init_config.softap_config.ssid, "ca-softap-$$$$DUB$$$$");
    strcpy(ca_init_config.softap_config.server_ip, "192.168.211.1");
    ca_init_config.ca_fl_start = (uint32_t)&ca_config_data;
    ca_init_config.ca_fl_size = sizeof(ca_config_data);

    ca_init_config.time_profile_config.disconnected_wifi_rescan_delay_timeout = 5;
    ca_init_config.time_profile_config.associated_dhcp_request_retry_timeout = 17;
    ca_init_config.time_profile_config.associated_check_connection_timeout = 35;
    ca_init_config.time_profile_config.check_connection_retry_timeout = 7;
    ca_init_config.time_profile_config.connected_joining_status_timeout = 10;
    ca_init_config.time_profile_config.connected_get_action_slow = 10;
    ca_init_config.time_profile_config.softap_start_delay = 30;

    res = ca_start(&ca_init_config);
    if (res != CA_RESULT_SUCCESS)
    {
        printf("Failed to start Cirrent Agent (error code %d)\n", res);
    }
    while (true)
    {
        //  print the memory stats if flag enabled
#ifdef CA_MBED_PRINT_STATS
        print_memory_stats();
#endif
        led1 = !led1;
        wait_us(3000000);
    }
}

#endif
