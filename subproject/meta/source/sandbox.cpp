// Copyright 2020 Junekey Jeon
//
// The contents of this file may be used under the terms of
// the Apache License v2.0 with LLVM Exceptions.
//
//    (See accompanying file LICENSE-Apache or copy at
//     https://llvm.org/foundation/relicensing/LICENSE.txt)
//
// Alternatively, the contents of this file may be used under the terms of
// the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE-Boost or copy at
//     https://www.boost.org/LICENSE_1_0.txt)
//
// Unless required by applicable law or agreed to in writing, this software
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.

#include "jkj/fp/dooly.h"
#include "jkj/fp/from_chars/from_chars.h"
#include "ryu/ryu.h"

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <stdexcept>
#include <memory>
#include <vector>

int main()
{
	using float_type = double;
	while (true) {
		std::string str;
		std::cin >> str;

		char buffer[64];
		auto x = jkj::fp::from_chars_unlimited<float_type>(str.data(), str.data() + str.length());

		if constexpr (std::is_same_v<float_type, float>) {
			f2s_buffered(x.to_float(), buffer);
		}
		else {
			d2s_buffered(x.to_float(), buffer);
		}
		std::cout << std::hexfloat <<
			std::setprecision(std::is_same_v<float_type, float> ? 6 : 13)
			<< x.to_float() << " (" << buffer << ")\n";
	}
}