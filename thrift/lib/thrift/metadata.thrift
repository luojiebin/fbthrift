/*
 * Copyright (c) Facebook, Inc. and its affiliates.
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

namespace cpp2 apache.thrift.metadata
namespace py apache.thrift.metadata
namespace py3 apache.thrift
namespace php tmeta

enum ThriftPrimitiveType {
  BOOL = 1;
  BYTE = 2;
  I16 = 3;
  I32 = 4;
  I64 = 5;
  FLOAT = 6;
  DOUBLE = 7;
  BINARY = 8;
  STRING = 9;
  VOID = 10;
}

struct ThriftListType {
  1: optional ThriftType valueType
    (cpp.ref = "true", cpp2.ref = "true", rust.box);
}

struct ThriftSetType {
  1: optional ThriftType valueType
    (cpp.ref = "true", cpp2.ref = "true", rust.box);
}

struct ThriftMapType {
  1: optional ThriftType keyType
    (cpp.ref = "true", cpp2.ref = "true", rust.box);
  2: optional ThriftType valueType
    (cpp.ref = "true", cpp2.ref = "true", rust.box);
}

struct ThriftEnumType {
  1: string name;
}

struct ThriftStructType {
  1: string name;
}

struct ThriftUnionType {
  1: string name;
}

struct ThriftTypedefType {
  1: string name;
  2: optional ThriftType underlyingType
    (cpp.ref = "true", cpp2.ref = "true", rust.box);
}

union ThriftType {
  1: ThriftPrimitiveType t_primitive;
  2: ThriftListType t_list;
  3: ThriftSetType t_set;
  4: ThriftMapType t_map;
  5: ThriftEnumType t_enum;
  6: ThriftStructType t_struct;
  7: ThriftUnionType t_union;
  8: ThriftTypedefType t_typedef;
}

struct ThriftEnum {
  1: string name;
  2: map<i32, string> elements;
}

struct ThriftField {
  1: i32 id;
  2: ThriftType type;
  3: string name;
  4: bool is_optional;
}

struct ThriftStruct {
  1: string name;
  2: list<ThriftField> fields;
  3: bool is_union;
}

struct ThriftException {
  1: string name;
  2: list<ThriftField> fields;
}

struct ThriftFunction {
  1: string name;
  2: ThriftType returnType;
  3: list<ThriftField> arguments;
  4: list<ThriftField> exceptions;
}

struct ThriftService {
  1: string name;
  2: list<ThriftFunction> functions;
  3: optional string parent;
}

// ThriftModuleContext represents module-specific metadata.
struct ThriftModuleContext {
  1: string name;
}

// ThriftServiceContext represents service-specific metadata.
struct ThriftServiceContext {
  1: ThriftService service_info;
  2: ThriftModuleContext module;
}

struct ThriftServiceMetadataResponse {
  1: ThriftServiceContext context;
  2: ThriftMetadata metadata;
}

/**
 * ThriftMetadata is for looking up types/exceptions with a specific name in
 * some environments, typically used by ThriftServiceMetadataResponse to
 * help finding definitions of a service's depending types/execptions.
 */
struct ThriftMetadata {
  // 1: string file_name;
  // ThriftMetadata is now used as a pure container for name lookup, and users
  // should use ThriftModuleContext instead if they want to get module name.
  2: map<string, ThriftEnum> enums;
  4: map<string, ThriftStruct> structs;
  5: map<string, ThriftException> exceptions;
  6: map<string, ThriftService> services;
}

service ThriftMetadataService {
  ThriftMetadata getRpcMetadata(); // deprecated
  ThriftServiceMetadataResponse getServiceMetadata();
}
