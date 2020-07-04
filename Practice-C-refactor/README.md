# Practice-C
 Simplify the step table/Create two fan zone/ Enable ambient table/power band

# Build

gcc main.c config.c hwmon.c -lpthread -o hwmon

# Design notes

1. Put all pre defines in config.h with sections like 'Marcos', 'Structures', 'Global Variables' and 'Functions'.
2. main() uses 3 functions to initialize config, get_system_entity(), get_system_fanzones() and get_system_power_capping_info() which are defined in config.c and declared in config.h.
3. Change entity_type to entity_combination.

# For get_system_entity()

### we have 3 unique entity and they are only here for test.

* If we use temp4Config0 for the argument in line 262, the result shows:

```
$ ./hwmon
get_system_fanzones: Checking entity#0...
0.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000

It matches the entity in checkAndReturnFanzoneConfig0(), so it calls loadFanzoneConfig0().
```

* If we use temp4Config1...

```
$ ./hwmon
get_system_fanzones: Checking entity#0...
get_system_fanzones: Checking entity#1...
0.000000, 21.000000, 22.000000, 23.000000, 24.000000, 25.000000, 26.000000, 27.000000
It doesn't match the entity in checkAndReturnFanzoneConfig0(), so it skips calling loadFanzoneConfig0().
Then, it matches the entity in checkAndReturnFanzoneConfig1(), so it calls loadFanzoneConfig1().
```

* If we use temp4Default...

```
$ ./hwmon
get_system_fanzones: Checking entity#0...
get_system_fanzones: Checking entity#1...
get_system_fanzones: Checking entity#2...
0.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000
It doesn't match the entity in checkAndReturnFanzoneConfig0(), so it skips calling loadFanzoneConfig0().
It doesn't match the entity in checkAndReturnFanzoneConfig1(), so it skips calling loadFanzoneConfig1().
Then, it calls loadFanzoneConfig1() because DEFAULT_CONFIG is loadFanzoneConfig1().
```

From results above, we can tell that 
