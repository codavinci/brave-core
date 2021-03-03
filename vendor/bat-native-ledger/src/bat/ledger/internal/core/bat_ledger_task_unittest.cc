/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ledger/internal/core/bat_ledger_task.h"

#include "bat/ledger/internal/core/bat_ledger_test.h"

namespace ledger {

class BATLedgerTaskTest : public BATLedgerTest {};

TEST_F(BATLedgerTaskTest, StartTask) {
  class Task : public BATLedgerTask<bool> {
   public:
    explicit Task(BATLedgerContext* context) : BATLedgerTask<bool>(context) {}

    void Start(int n) {
      AsyncResult<int>::Resolver resolver;
      resolver.result().Listen(Continuation(&Task::OnDone));
      resolver.Complete(std::move(n));
    }

   private:
    void OnDone(const int& n) { Complete(static_cast<bool>(n)); }
  };

  bool value = false;
  context()->StartTask<Task>(10).Listen(
      base::BindLambdaForTesting([&value](const bool& v) { value = v; }));

  task_environment()->RunUntilIdle();
  EXPECT_TRUE(value);
}

}  // namespace ledger
