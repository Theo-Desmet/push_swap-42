# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_generator.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 15:13:42 by bbordere          #+#    #+#              #
#    Updated: 2022/01/28 09:11:52 by tdesmet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

file = open("rstack.txt", 'w')
t=random.sample(range(-250, 250), int(sys.argv[1]))
for n in t:
	stri = str(n) + " "
	file.write(stri)
file.truncate()
file.close()
