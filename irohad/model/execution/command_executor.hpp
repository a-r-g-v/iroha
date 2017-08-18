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

#ifndef IROHA_COMMAND_EXECUTOR_HPP
#define IROHA_COMMAND_EXECUTOR_HPP

#include "ametsuchi/wsv_command.hpp"
#include "ametsuchi/wsv_query.hpp"
#include "model/command.hpp"

namespace iroha {
  namespace model {
    class CommandExecutor {
     public:
      bool validate(const Command &command, ametsuchi::WsvQuery &queries,
                    const Account &creator);

      virtual bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                           ametsuchi::WsvCommand &commands) = 0;

      virtual ~CommandExecutor() = default;

     protected:
      virtual bool hasPermissions(const Command &command,
                                  ametsuchi::WsvQuery &queries,
                                  const Account &creator) = 0;

      virtual bool isValid(const Command &command,
                           ametsuchi::WsvQuery &queries) = 0;
    };

    class AddAssetQuantityExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class AddPeerExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class AddSignatoryExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class AssignMasterKeyExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class CreateAccountExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class CreateAssetExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class CreateDomainExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class RemoveSignatoryExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class SetAccountPermissionsExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class SetQuorumExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };

    class TransferAssetExecutor : public CommandExecutor {
     public:
      bool execute(const Command &command, ametsuchi::WsvQuery &queries,
                   ametsuchi::WsvCommand &commands) override;

     protected:
      bool hasPermissions(const Command &command, ametsuchi::WsvQuery &queries,
                          const Account &creator) override;

      bool isValid(const Command &command,
                   ametsuchi::WsvQuery &queries) override;
    };
  }  // namespace model
}  // namespace iroha

#endif  // IROHA_COMMAND_EXECUTOR_HPP
