/*
 * Copyright (C) 2018-2025 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses

import org.perses.cmd.CacheControlFlagGroup
import org.perses.cmd.ExperimentFlagGroup
import org.perses.cmd.InputFlagGroup
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.OutputRefiningFlagGroup
import org.perses.cmd.ProfilingFlagGroup
import org.perses.cmd.ReductionAlgorithmControlFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.cmd.TRecFlagGroup
import org.perses.cmd.VulcanFlagGroup
import org.perses.util.cmd.AbstractCommandOptions

/** Parser for command line arguments.  */
open class CommandOptions : AbstractCommandOptions() {

  val inputFlags = registerFlags(createInputFlags())

  val resultOutputFlags = registerFlags(OutputFlagGroup())

  val reductionControlFlags = registerFlags(ReductionControlFlagGroup())

  val outputRefiningFlags = registerFlags(OutputRefiningFlagGroup())

  val algorithmControlFlags = registerFlags(
    ReductionAlgorithmControlFlagGroup(),
  )

  val languageControlFlags = registerFlags(LanguageControlFlagGroup())

  val vulcanFlags = registerFlags(VulcanFlagGroup())

  val trecFlags = registerFlags(TRecFlagGroup())

  val profilingFlags = registerFlags(ProfilingFlagGroup())

  val cacheControlFlags = registerFlags(CacheControlFlagGroup())

  val experimentFlags = registerFlags(ExperimentFlagGroup())

  open fun createInputFlags() = InputFlagGroup()
}
