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

#include <fstream>
#include <string>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

bool check_cmdline(const std::string &param){
    std::ifstream file("/proc/cmdline");
    if (file.good()) {
        std::string line;
        while (std::getline(file, line, ' ')) {
            if(line == param)
                return true;
        }
    }
    return false;
}

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties() {
    std::string serial = property_get("ro.boot.serialno");

    if (serial.substr(0,6) ==   "LGLS620") {
        property_override("ro.product.model", "LGLS620");
        property_override("ro.product.device", "w5c");
        property_override("ro.build.description", "w5c_spr_us-user 4.4.2 KOT49I.LS620ZV3 LS620ZV3.1401441831 release-keys");
        property_override("ro.build.fingerprint", "lge/w5c_spr_us/w5c:4.4.2/KOT49I.LS620ZV3/LS620ZV3.1401441831:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.multisim.config", "");
    } else {
        /* XXX */
        property_override("ro.product.device", "w5c");
        property_override("ro.product.model", "Please write your model name to electi@yzu.moe");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.multisim.config", "");
    }

    std::string device = property_get("ro.product.device");

    ERROR("Found hardware id: %s setting build properties for %s device\n", serial.c_str(), device.c_str());
}
