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

#ifndef CONSENSUS_CONNECTION_SERVICE_HPP
#define CONSENSUS_CONNECTION_SERVICE_HPP

#include <logger.pb.h>
#include <logger.grpc.pb.h>

namespace logger {
  namespace connection {

    class LoggerLivingConfirmationService final
      : public iroha::protocol::LoggerLivingConfirmationService::Service {
    public:
      grpc::Status check(
        grpc::ServerContext* context, const ::iroha::protocol::Ping* ping,
        iroha::protocol::Pong* pong);
    };

  }  // namespace connection
}  // namespace consensus

#endif // CONSENSUS_CONNECTION_SERVICE_HPP