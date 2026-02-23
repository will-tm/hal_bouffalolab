/*
 * Minimal utils_list ABI definition needed by the Wi-Fi blob-facing structs.
 */

#ifndef _UTILS_LIST_H_
#define _UTILS_LIST_H_

struct utils_list_hdr {
	struct utils_list_hdr *next;
};

struct utils_list {
	struct utils_list_hdr *first;
	struct utils_list_hdr *last;
};

#endif /* _UTILS_LIST_H_ */
