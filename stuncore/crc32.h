/* Source: http://home.thep.lu.se/~bjorn/crc/
 *
 * Simple public domain implementation of the standard CRC32 checksum.
 * Outputs the checksum for each file given as a command line argument.
 * Invalid file names and files that cause errors are silently skipped.
 * The program reads from stdin if it is called with no arguments. */

#include <cstdio>
#include <cstdint>
#include <cstdlib>

uint32_t crc32(const void* data, size_t n_bytes);
