/* Copyright 2019 DanDobrick
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// place overrides here

// Tap dance timing
#define TAPPING_TERM 175
// Leader key timing
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#ifdef V60_POLESTAR
#undef V60_POLESTAR
#endif
