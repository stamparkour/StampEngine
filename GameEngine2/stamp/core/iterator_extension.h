//stamp/core/iterator_extension.h

#pragma once
#ifndef STAMP_CORE_iterator_EXTENSION_H
#define STAMP_CORE_iterator_EXTENSION_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <stamp/core/define.h>
#include <iterator>
#include <type_traits>

STAMP_NAMESPACE_BEGIN

template<typename Iter, typename Deref>
concept iterator_derefrence_to = std::same_as<Deref, std::iter_value_t<Iter>>;

template<typename Iter, typename Deref>
concept forward_iterator_derefrence_to = std::forward_iterator<Iter> && iterator_derefrence_to<Iter, Deref>;

template<typename Iter, typename Deref>
concept contiguous_iterator_derefrence_to = std::contiguous_iterator<Iter> && iterator_derefrence_to<Iter, Deref>;

STAMP_NAMESPACE_END

#endif