# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_generator.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 15:13:42 by bbordere          #+#    #+#              #
#    Updated: 2022/02/01 08:14:31 by tdesmet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

file = open("rstack.txt", 'w')
t=random.sample(range(-50, 50), int(sys.argv[1]))
for n in t:
	stri = str(n) + " "
	file.write(stri)
file.truncate()
file.close()
