# Copyright (C) 1996, 1998 A. Scottedward Hodel 
#
# This file is part of Octave. 
#
# Octave is free software; you can redistribute it and/or modify it 
# under the terms of the GNU General Public License as published by the 
# Free Software Foundation; either version 2, or (at your option) any 
# later version. 
# 
# Octave is distributed in the hope that it will be useful, but WITHOUT 
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License 
# for more details.
# 
# You should have received a copy of the GNU General Public License 
# along with Octave; see the file COPYING.  If not, write to the Free 
# Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 
function str_val = outlist(name_list,tabchar,yd,ilist)
# function str_val = outlist(name_list[,tabchar,yd,ilist])
#
# internal use only; minimal argument checking performed
#
# print an enumerated list of strings
# inputs:
#	name_list: list of strings (one per entry)
#	tabchar: tab character (default: none)
#       yd: indices of entries to append with the string "(discrete)"
#           (used by sysout; minimal checking of this argument)
#	   yd = [] => all continuous
#       ilist: index numbers to print with names
#	  default: 1:length(name_list)
# outputs:
#   prints the list to the screen, numbering each string in order.

# A. S. Hodel Dec. 1995, 1998

#save for restore later
save_empty = empty_list_elements_ok;
empty_list_elements_ok = 1;

if( nargin < 1 | nargin > 4 )
  usage("str_val = outlist(x[,tabchar,yd,ilist])");
endif

m = length(name_list);
if(nargin < 4)           ilist = 1:m;          endif
if(nargin ==1)
  empty_list_elements_ok = 1;
  tabchar = "";
endif

if(nargin < 3)             yd = zeros(1,m);
elseif(isempty(yd))        yd = zeros(1,m);          endif

str_val = "";
dstr = list(""," (discrete)");
if((m >= 1) && (is_list(name_list)))
  for ii=1:m
    str_val = sprintf("%s%s%d: %s%s\n",str_val,tabchar, ii, ...
	nth(name_list,ii),nth(dstr,yd(ii)+1));
  endfor
else
  str_val = sprintf("%sNone",tabchar);
endif

empty_list_elements_ok = save_empty;
endfunction
