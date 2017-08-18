/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ORDERING_GATE_TRANSPORT_HPP
#define ORDERING_GATE_TRANSPORT_HPP

#include "model/peer.hpp"
#include "model/transaction.hpp"
#include "model/proposal.hpp"
#include "ordering.grpc.pb.h"


namespace iroha {
  namespace network {
    struct ProposalContext{};

    class OrderingGateNotification {
    public:
      virtual void handleProposal(std::shared_ptr<iroha::model::Proposal>) = 0;

      virtual ~OrderingGateNotification() = default;
    };


    class OrderingGateTransport {
    protected:
      std::shared_ptr<OrderingGateNotification> subscriber_ {nullptr};

    public:
      virtual void propagate(std::shared_ptr<const iroha::model::Transaction>) = 0;

      virtual void subscribe(std::shared_ptr<OrderingGateNotification>) = 0;

      virtual std::shared_ptr<model::Proposal> getProposal(const iroha::ordering::proto::Proposal *request) = 0;


      virtual ~OrderingGateTransport() = default;
    };

  }
}

#endif
