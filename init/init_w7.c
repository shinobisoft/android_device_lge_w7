/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* See EOF for Edit notes */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

#define CHUNK 2048 /* read 2048 bytes at a time */

int check_cmdline(char param[]) {

    char buf[CHUNK];
    FILE *file;
    size_t nread;
    file = fopen("/proc/cmdline", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
                /* fwrite(buf, 1, nread, stdout); */
                char delims[] = " ";
                char *word = NULL;
                word = strtok(buf, delims);

                while(word != NULL) {
                        if (!strcmp(param,word)) {
                                fclose(file);
                                return 1;
                        }
                        word = strtok(NULL, delims);
                }
        }
    }	
    fclose(file);
    return 0;
}

 
void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char serial[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    property_get("ro.boot.serialno", serial);
    
    if( !strncmp( serial, "LGD400", 6 ) ) {
        /* D400, D400n, D400hn */
        if ( check_cmdline("model.name=LG-D400n") == 1 || check_cmdline("model.name=LG-D400hn") == 1 ) {
            if( check_cmdline("model.name=LG-D400n") == 1 ) {
                property_set("ro.product.device", "w7n");
                property_set("ro.product.model", "LG-D400n");
                property_set("persist.radio.multisim.config", "");
                
            } else {
                property_set("ro.product.device", "w7nds");
                property_set("ro.product.model", "LG-D400hn");
                property_set("persist.radio.multisim.config", "dsds");
                
            }
            property_set("ro.nfc.port", "I2C");
            
        } else { // LG-D400???
            property_set("ro.product.device", "w7");
            property_set("ro.product.model", "LG-D400");
            property_set("persist.radio.multisim.config", "");
            property_set("ro.nfc.port", "");
            
        }
        property_set("ro.build.description", "w7_global_sca-user 4.4.2 KOT49I.V10a 1398486791 release-keys");
        property_set("ro.build.fingerprint", "lge/w7_global_sca/w7:4.4.2/KOT49I.V10a/1398486791:user/release-keys");
        
    } else if (strncmp(serial, "LGD405", 6) == 0) {
        /* D405, D405n, D405hn??? */
        if ( check_cmdline("model.name=LG-D405n") == 1 || check_cmdline("model.name=LG-D405hn") == 1 ) {
            if( check_cmdline("model.name=LG-D405n") == 1 ) {
                // Single-sim with NFC
                property_set("ro.product.device", "w7n");
                property_set("ro.product.model", "LG-D405n");
                property_set("persist.radio.multisim.config", "");
                property_set("ro.build.description", "w7n_global_com-user 4.4.2 KOT49I.A1400215746 1400215746 release-keys");
                property_set("ro.build.fingerprint", "lge/w7n_global_com/w7n:4.4.2/KOT49I.A1400215746/1400215746:user/release-keys");
                
            } else {
                // Dual-sim with NFC
                property_set("ro.product.device", "w7nds");
                property_set("ro.product.model", "LG-D405hn");
                property_set("persist.radio.multisim.config", "dsds");
                property_set("ro.build.description", "w7ds_global_com-user 4.4.2 KOT49I.A1400215746 1400215746 release-keys");
                property_set("ro.build.fingerprint", "lge/w7ds_global_com/w7ds:4.4.2/KOT49I.A1400215746/1400215746:user/release-keys");
                
            }
            property_set("ro.nfc.port", "I2C");
         
        } else {
            // Single-sim without NFC
            property_set("ro.product.model", "LG-D405");
            property_set("ro.product.device", "w7");
            property_set("persist.radio.multisim.config", "");
            property_set("ro.nfc.port", "");
            property_set("ro.build.description", "w7_global_com-user 4.4.2 KOT49I.A1402966338 1402966338 release-keys");
            property_set("ro.build.fingerprint", "lge/w7_global_com/w7:4.4.2/KOT49I.A1402966338/1402966338:user/release-keys");
        }
        
        
    } else if (strncmp(serial, "LGD410", 6) == 0) {
        /* D410n, D410hn */
        if (check_cmdline("model.name=LG-D410hn") == 1 || check_cmdline("model.name=LG-D410n") == 1) {
            if (check_cmdline("model.name=LG-D410hn") == 1) {
                    property_set("ro.product.device", "w7nds");
                    property_set("ro.product.model", "LG-D410hn");
                    property_set("persist.radio.multisim.config", "dsds");
            } else {
                    property_set("ro.product.device", "w7n");
                    property_set("ro.product.model", "LG-D410n");
                    property_set("persist.radio.multisim.config", "");
            }
            property_set("ro.nfc.port", "I2C");
            
        } else {
            property_set("ro.product.model", "LG-D410");
            property_set("ro.product.device", "w7");
            property_set("persist.radio.multisim.config", "");
            property_set("ro.nfc.port", "");
        }
        
        property_set("ro.build.description", "w7ds_global_com-user 4.4.2 KOT49I.A1398228431 1398228431 release-keys");
        property_set("ro.build.fingerprint", "lge/w7ds_global_com/w7ds:4.4.2/KOT49I.A1398228431/1398228431:user/release-keys");
        
    } else if (strncmp(serial, "LGD415", 6) == 0) {
        /* D415 */
        property_set("ro.product.device", "w7");
        property_set("ro.product.model", "LG-D415");
        property_set("ro.build.description", "w7_tmo_us-user 4.4.2 KOT49I.D41510c D41510c.1393916607 release-keys");
        property_set("ro.build.fingerprint", "lge/w7_tmo_us/w7:4.4.2/KOT49I.D41510c/D41510c.1393916607:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("ro.nfc.port", "");
        
    } else {
        /*  This should technically never happen  */
        /* XXX */
        property_set("ro.product.device", "w7");
        property_set("ro.product.model", "Please write your model name to agent00791@gmail.com");
        property_set("persist.radio.multisim.config", "");
        
    }
    property_set("telephony.lteOnCdmaDevice", "0");
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found hardware id: %s setting build properties for %s device\n", serial, devicename);
}

/*
  Last Edit By: shinobisoft @ xda-developers
  Date: 11/01/2014
  Reason(s):
    - Each device has it's own unique 'ro.build.description' and 'ro.build.fingerprint'.
      - D405** - Update properties -> ro.build.description, ro.build.fingerprint
*/

/* 
  Last Edit By: shinobisoft @ xda-developers
  Date: 10/29/2014
  Reason(s):
      - Reordered the device code.
      - Added complete support for all known device variants
        D400, D400n, D400hn, D405, D405n, D405hn, D410, D410n, D410hn, D415
*/

/*
  Last Edit By: shinobisoft @ xda-developers
  Date: 10/06/2014
  Reason(s):
      Code clean-up. Remove duplicate 'property_set("telephony.lteOnCdmaDevice", "0")' calls.
        It's common with all devices so why not just write it once.
*/

/*
  Last Edit By: shinobisoft @ xda-developers
  Date: 09/26/2014
  Reason(s):
      Added support for LG-D400 model
      General code cleanup ( for more readability )
      Condensed code for LG-D415:
        Removed 'if, else if' conditionals for LG-D415 model since there
        is only one US model available
*/
