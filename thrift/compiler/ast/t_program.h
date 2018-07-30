/*
 * Copyright 2016-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <thrift/compiler/ast/t_base_type.h>
#include <thrift/compiler/ast/t_const.h>
#include <thrift/compiler/ast/t_doc.h>
#include <thrift/compiler/ast/t_enum.h>
#include <thrift/compiler/ast/t_list.h>
#include <thrift/compiler/ast/t_map.h>
#include <thrift/compiler/ast/t_scope.h>
#include <thrift/compiler/ast/t_service.h>
#include <thrift/compiler/ast/t_set.h>
#include <thrift/compiler/ast/t_stream.h>
#include <thrift/compiler/ast/t_struct.h>
#include <thrift/compiler/ast/t_typedef.h>

namespace apache {
namespace thrift {
namespace compiler {

/**
 * class t_program
 *
 * Top level class representing an entire thrift program. A program consists
 * fundamentally of the following:
 *
 *   Typedefs
 *   Enumerations
 *   Constants
 *   Structs
 *   Exceptions
 *   Services
 *
 * The program module also contains the definitions of the base types.
 */
class t_program : public t_doc {
 public:
  /**
   * Constructor for t_program
   *
   * @param path - A *.thrift file path.
   */
  explicit t_program(std::string path) : path_(std::move(path)) {}

  /**
   * Set program elements
   */
  void add_typedef(t_typedef* td) {
    typedefs_.push_back(td);
  }
  void add_enum(t_enum* te) {
    enums_.push_back(te);
  }
  void add_const(t_const* tc) {
    consts_.push_back(tc);
  }
  void add_struct(t_struct* ts) {
    objects_.push_back(ts);
    structs_.push_back(ts);
  }
  void add_xception(t_struct* tx) {
    objects_.push_back(tx);
    xceptions_.push_back(tx);
  }
  void add_service(t_service* ts) {
    services_.push_back(ts);
  }

  /**
   * Get program elements
   */
  const std::vector<t_typedef*>& get_typedefs() const {
    return typedefs_;
  }
  const std::vector<t_enum*>& get_enums() const {
    return enums_;
  }
  const std::vector<t_const*>& get_consts() const {
    return consts_;
  }
  const std::vector<t_struct*>& get_structs() const {
    return structs_;
  }
  const std::vector<t_struct*>& get_xceptions() const {
    return xceptions_;
  }
  const std::vector<t_struct*>& get_objects() const {
    return objects_;
  }
  const std::vector<t_service*>& get_services() const {
    return services_;
  }

  /**
   * t_program setters
   */
  void add_cpp_include(std::string path) {
    cpp_includes_.push_back(std::move(path));
  }

  // Only used in py_frontend.tcc
  void set_namespace(std::string name) {
    namespace_ = std::move(name);
  }

  /**
   * Language neutral namespace/packaging
   *
   * @param language - The target language (i.e. py, cpp) to generate code
   * @param name_space - //TODO add definition of name_space
   */
  void set_namespace(std::string language, std::string name_space) {
    namespaces_.emplace(language, name_space);
  }

  /**
   * t_program getters
   */
  bool is_out_path_absolute() const {
    return out_path_is_absolute_;
  }

  const std::string& get_path() const {
    return path_;
  }

  const std::string& get_out_path() const {
    return out_path_;
  }

  const std::string& get_name() const {
    return name_;
  }

  const std::string& get_namespace() const {
    return namespace_;
  }

  const std::string& get_include_prefix() const {
    return include_prefix_;
  }

  const std::vector<t_program*>& get_included_programs() const {
    return includes_;
  }

  t_scope* scope() const {
    return scope_.get();
  }

  // Only used in py_frontend.tcc
  const std::map<std::string, std::string>& get_namespaces() const {
    return namespaces_;
  }

  // Only used in t_cpp_generator
  const std::vector<std::string>& get_cpp_includes() const {
    return cpp_includes_;
  }

  /**
   * Outputs a reference to the namespace corresponding to the
   * key(language) in the namespaces_ map.
   *
   * @param language - The target language (i.e. py, cpp) to generate code
   */
  const std::string& get_namespace(const std::string& language) const;

  /**
   * Set a file path to a correctly formated output path
   *
   * @param out_path             - The output folder for the autogenerated code
   * @param out_path_is_absolute - Determines if out_path is an absolute path
   */
  void set_out_path(std::string out_path, bool out_path_is_absolute);

  /**
   * This creates a new program for every thrift file in an
   * include statement and sets their include_prefix by parsing
   * the directory in which they were included from
   *
   * @param path         - A full thrift file path
   * @param include_site - A full or relative thrift file path
   */
  t_program* add_include(std::string path, std::string include_site);

  void add_include(t_program* program) {
    includes_.push_back(program);
  }

  /**
   * This sets the directory path of the current thrift program,
   * adding checks to format it into a correct directory path
   *
   * @param include_prefix - The directory path of a thrift include statement
   */
  void set_include_prefix(std::string include_prefix);

  /**
   *  Obtains the name of a thrift file from the full file path
   *
   * @param path - A *.thrift file path
   */
  std::string compute_name_from_file_path(std::string path);

 private:
  /**
   * Components to generate code for
   */
  std::vector<t_typedef*> typedefs_;
  std::vector<t_enum*> enums_;
  std::vector<t_const*> consts_;
  std::vector<t_struct*> objects_;
  std::vector<t_struct*> structs_;
  std::vector<t_struct*> xceptions_;
  std::vector<t_service*> services_;

  bool out_path_is_absolute_{false};
  std::string path_; // initialized in ctor init-list
  std::string name_{compute_name_from_file_path(path_)};
  std::string out_path_{"./"};
  std::string namespace_;
  std::vector<t_program*> includes_;
  std::string include_prefix_;
  std::map<std::string, std::string> namespaces_;
  std::vector<std::string> cpp_includes_;
  std::unique_ptr<t_scope> scope_{new t_scope{}};
};

} // namespace compiler
} // namespace thrift
} // namespace apache
