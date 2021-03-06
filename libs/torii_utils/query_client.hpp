/*
Copyright 2017 Soramitsu Co., Ltd.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef TORII_UTILS_QUERY_CLIENT_HPP
#define TORII_UTILS_QUERY_CLIENT_HPP

#include <endpoint.grpc.pb.h>
#include <endpoint.pb.h>
#include <grpc++/grpc++.h>
#include <grpc++/channel.h>
#include <memory>
#include <thread>

namespace torii_utils {

  /**
   * CommandSyncClient
   */
  class QuerySyncClient {
  public:
    QuerySyncClient(const std::string& ip, const int port);
    ~QuerySyncClient();

    /**
     * requests query to a torii server and returns response (blocking, sync)
     * @param query - contains Query what clients request.
     * @param response - QueryResponse that contains what clients want to get.
     * @return grpc::Status
     */
    grpc::Status Find(const iroha::protocol::Query &query, iroha::protocol::QueryResponse &response);

  private:
    grpc::ClientContext context_;
    std::unique_ptr<iroha::protocol::QueryService::Stub> stub_;
    grpc::CompletionQueue completionQueue_;
    grpc::Status status_;
  };

  /**
   * QueryAsyncClient

  // Impelent here if we need this.

  class QueryAsyncClient {
  };
   */

}  // namespace torii

#endif  // TORII_UTILS_QUERY_CLIENT_HPP
