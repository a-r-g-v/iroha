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

#ifndef CONSENSUS_CONNECTION_CLIENT_HPP
#define CONSENSUS_CONNECTION_CLIENT_HPP

#include <grpc++/grpc++.h>
#include <memory>
#include <logger.pb.h>
#include <logger.grpc.pb.h>

namespace logger {
  namespace connection {

    bool check(const std::string& address);

    class LoggerLivingConfirmationClient {
    public:
      LoggerLivingConfirmationClient(const std::string& address);
      bool check(const iroha::protocol::Ping&);
    private:
      grpc::ClientContext context_;
      std::unique_ptr<iroha::protocol::LoggerLivingConfirmationService::Stub> stub_;
    };

  }  // namespace connection
}  // namespace consensus

#endif // CONSENSUS_CONNECTION_CLIENT_HPP