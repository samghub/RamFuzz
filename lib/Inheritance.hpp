// Copyright 2016 The RamFuzz contributors. All rights reserved.
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

#pragma once

#include "clang/AST/DeclCXX.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/Twine.h"

namespace ramfuzz {
/// Maps a class to all subclasses that inherit from it directly.
using Inheritance =
    llvm::DenseMap<const clang::CXXRecordDecl *,
                   llvm::SmallPtrSet<const clang::CXXRecordDecl *, 4>>;

/// Calculates inheritance among classes in code.
Inheritance findInheritance(const llvm::Twine &code);

/// Calculates inheritance among classes in tool.
Inheritance findInheritance(clang::tooling::ClangTool &tool);
}
