/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_DATABASE_DATABASE_SERVER_PUBLISHER_LINKS_H_
#define BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_DATABASE_DATABASE_SERVER_PUBLISHER_LINKS_H_

#include <string>

#include "base/containers/flat_map.h"
#include "bat/ledger/mojom_structs.h"
#include "brave/components/brave_rewards/browser/database/database_table.h"

namespace brave_rewards {

class DatabaseServerPublisherLinks: public DatabaseTable {
 public:
  explicit DatabaseServerPublisherLinks(int current_db_version);
  ~DatabaseServerPublisherLinks() override;

  bool Init(sql::Database* db) override;

  bool CreateTable(sql::Database* db) override;

  bool CreateIndex(sql::Database* db) override;

  bool Migrate(sql::Database* db, const int target);

  bool InsertOrUpdate(sql::Database* db, ledger::ServerPublisherInfoPtr info);

  base::flat_map<std::string, std::string> GetRecord(
      sql::Database* db,
      const std::string& publisher_key);

 private:
  bool CreateTableV7(sql::Database* db);

  bool CreateTableV15(sql::Database* db);

  bool CreateIndexV7(sql::Database* db);

  bool CreateIndexV15(sql::Database* db);

  bool MigrateToV7(sql::Database* db);

  bool MigrateToV15(sql::Database* db);
};

}  // namespace brave_rewards

#endif  // BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_DATABASE_DATABASE_SERVER_PUBLISHER_LINKS_H_
