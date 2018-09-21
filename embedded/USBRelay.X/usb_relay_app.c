#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "usb_relay_app.h"

uint8_t RelayApp_ParseCommand(char* i_data, t_relay_data *realy_data){
    
    const char relay_params[] = "RSPDC";
    uint8_t i;
    char* param_pointer;
    //1. to upper
    for(i=0; i < (strlen(i_data)-1); ++i)
    {
       i_data[i] = toupper(i_data[i]);
    }
    //2. Cycle by all params
    param_pointer = strpbrk(i_data, relay_params);
    while (param_pointer != NULL)
    {
        // 2a. extract value from parameter
        char *pNumberEnd;
        uint32_t tmp_val = strtol(param_pointer+1,&pNumberEnd,10);
        // 2b. parameter check
        switch(param_pointer[0])
        {
            case 'R':
            {
                if ((pNumberEnd == NULL) || ((tmp_val >= MAX_RELAY_NO)))
                {
                    return 0;
                } else
                {
                    realy_data->relay_number = tmp_val;
                }
                break;
            }
            case 'S':
            {
            	if ((pNumberEnd == NULL) || ((tmp_val >= 2)))
				{
					return 0;
				} else
				{
					realy_data->is_closed = tmp_val;
				}
				break;
            }
            case 'P':
            {
            	if (pNumberEnd == NULL)
				{
					/* do nothing */
				} else
				{
					realy_data->period_ms = tmp_val;
				}
				break;
            }
            case 'D':
            {
            	if (pNumberEnd == NULL)
				{
					/* do nothing */
				} else
				{
					realy_data->delay_ms = tmp_val;
				}
				break;
            }
            case 'C':
            {
            	if (pNumberEnd == NULL)
				{
					/* do nothing */
				} else
				{
					realy_data->operation_count = tmp_val;
				}
				break;
            }
            default:  
                break;
        }
        param_pointer = strpbrk (param_pointer + 1, relay_params);
    }
    return 1;
}
