/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
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
#ifndef LIEF_VERSION_H_
#define LIEF_VERSION_H_

#if defined(NDEBUG)
  //#define LIEF_NAME "@PROJECT_NAME@"
  #define LIEF_NAME "LIEF"
#else
  //#define LIEF_NAME "@PROJECT_NAME@ (Debug)"
  #define LIEF_NAME "LIEF (Debug)"
#endif

//#define LIEF_VERSION "@LIEF_VERSION_MAJOR@.@LIEF_VERSION_MINOR@.@LIEF_VERSION_PATCH@-@LIEF_COMMIT_HASH@"
#define LIEF_VERSION "0.8.3-66b484938aefdb33143f8a963cf931eebc304a47"

#define HUMAN_VERSION " v" LIEF_VERSION
#define HUMAN_NAME NAME HUMAN_VERSION

#endif