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

#include "to_chars_fixed_precision_benchmark.h"
#include "ryu/ryu.h"

namespace {
	void float_to_chars(float x, char* buffer, int precision)
	{
		d2exp_buffered(x, precision, buffer);
	}
	void double_to_chars(double x, char* buffer, int precision)
	{
		d2exp_buffered(x, precision, buffer);
	}

	auto dummy = []() -> register_function_for_to_chars_fixed_precision_benchmark {
		return{ "Ryu",
			float_to_chars,
			double_to_chars
		};
	}();
}