# Copyright (c) 2020, Xianguang Zhou <xianguang.zhou@outlook.com>. All rights reserved.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

project('light_stackless_coroutine', 'c', default_options : ['optimization=0'])

install_headers('light_stackless_coroutine.h')

src_list = ['light_stackless_coroutine.c'
		  , 'lsc_context_x86.S'
		  , 'lsc_context_arm.S'
		  , 'lsc_context_arm64.S'
		  ]

library(meson.project_name(),
	sources : src_list,
	include_directories : [],
	dependencies : [],
	install : true)
