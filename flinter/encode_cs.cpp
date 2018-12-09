/* Copyright 2014 yiyuanzhong@gmail.com (Yiyuan Zhong)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flinter/encode.h"

#include "config.h"
#if HAVE_CLEARSILVER_CLEARSILVER_H
#include <ClearSilver/ClearSilver.h>

namespace flinter {
std::string EncodeUrl(const std::string &url)
{
    char *ret;
    NEOERR *err = cgi_url_escape(url.c_str(), &ret);
    if (err != STATUS_OK) {
        nerr_ignore(&err);
        return std::string();
    }

    std::string result = ret;
    free(ret);
    return result;
}

std::string DecodeUrl(const std::string &url)
{
    std::string copy(url);
    return cgi_url_unescape(&copy[0]);
}

} // namespace flinter
#endif // HAVE_CLEARSILVER_CLEARSILVER_H
