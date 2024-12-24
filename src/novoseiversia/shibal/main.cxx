// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <novoseiversia@gmail.com>

#include <cstdlib>

#include <memory>

#include "cli/clifilesession.h"



auto main() -> int
{
	auto scheduler = std::make_unique<cli::Menu>("scheduler");



	auto root = std::make_unique<cli::Menu>("shibal");

	root->Insert(std::move(scheduler));



	auto cli = cli::Cli(std::move(root));

	auto session = cli::CliFileSession(cli);

	session.Start();



	return EXIT_SUCCESS;
}
