NetworkDIY
==============================

[英文说明 (English Version)](./README_en.md)

这里是 CS144 和 CS168 的混合学习路线，基本思路是学 CS168 的资料而做 CS144 的作业。CS168 公开了最新年份的电子版教材和视频，授课老师幽默风趣；CS144 提供的作业基于现代 C++，因此这条学习路线能同时满足学习计网和现代 C++ 的需求。

每个阶段的学习流程如下：
1. 学习这个阶段的 CS168 Lectures 和 Readings，可以在 [这个Youtube视频列表](https://www.youtube.com/playlist?list=PL0_XloRC3MWs5MylcqPFEeTCx0RQocrD7) 找到课程录屏。
2. 参考 [handouts](./handouts/) 里的实验文档完成这个阶段的 CS144 Lab
3. 进入下一个阶段

CS144 只有 10 周，而 CS168 有 16 周，所以在最后两个阶段会有只有课没有 Lab 的情况。

| 资源名 | 链接 |
| :--- | :--- |
| CS168 SP25 官网 | https://sp25.cs168.io/
| CS168 教材 | https://textbook.cs168.io/
| CS168 SP25 视频列表 | https://www.youtube.com/playlist?list=PL0_XloRC3MWs5MylcqPFEeTCx0RQocrD7 |
| CS144 官网 | https://cs144.github.io/ |
| CS144 Labs | https://github.com/CS144/minnow |

| 阶段 | CS144 Lab | CS168 Lectures | CS168 Readings |
| :--- | :--- | :--- | :--- |
| P1 | Lab 0: ByteStream | 1. Intro 1: Layers of the Internet<br>2. Intro 2: Design Principles | [Intro](https://textbook.cs168.io/intro/intro.html), [Layers](https://textbook.cs168.io/intro/layers.html), [Headers](https://textbook.cs168.io/intro/headers.html)<br>[Architecture](https://textbook.cs168.io/intro/architecture.html), [Design](https://textbook.cs168.io/intro/sharing-resources.html) |
| P2 | Lab 1: Reassembler | 3. Intro 3: Links | [Links](https://textbook.cs168.io/intro/links.html), [Multiplexing](https://textbook.cs168.io/intro/sharing-resources.html) |
| P3 | Lab 2: TCP Receiver | 11-12. Transport 1: TCP | [Principles (Reliability)](https://textbook.cs168.io/transport/reliability.html)<br>[Design](https://textbook.cs168.io/transport/tcp-design.html), [Implementation](https://textbook.cs168.io/transport/tcp-implementation.html) |
| P4 | Lab 3: TCP Sender | 13-15. Transport 3: Congestion Control | [Principles](https://textbook.cs168.io/transport/cc-principles.html), [Design](https://textbook.cs168.io/transport/cc-design.html), [Implementation](https://textbook.cs168.io/transport/cc-implementation.html)<br>[Throughput](https://textbook.cs168.io/transport/throughput-model.html), [Issues](https://textbook.cs168.io/transport/cc-issues.html), [Router-Assisted](https://textbook.cs168.io/transport/router-based-cc.html) |
| P5 | Lab 4: Real World | 4-6. Routing 1-2: Principles, Distance-Vector | [Intro](https://textbook.cs168.io/routing/intro.html), [Model](https://textbook.cs168.io/routing/model.html), [States](https://textbook.cs168.io/routing/solutions.html)<br>[Distance-Vector](https://textbook.cs168.io/routing/distance-vector.html) |
| P6 | Lab 5: Network Interface | 18-20. End-to-End: Ethernet, STP, ARP, DHCP | [Ethernet](https://textbook.cs168.io/end-to-end/ethernet.html), [STP (L2 Routing)](https://textbook.cs168.io/end-to-end/l2-routing.html)<br>[ARP](https://textbook.cs168.io/end-to-end/arp.html), [DHCP](https://textbook.cs168.io/end-to-end/dhcp.html), [NAT](https://textbook.cs168.io/end-to-end/nat.html), [TLS](https://textbook.cs168.io/end-to-end/tls.html), [End-to-End](https://textbook.cs168.io/end-to-end/end-to-end.html) |
| P7 | Lab 6: IP Router | 7-8. Routing 3-4: Link-State, Addressing, Routers | [Link-State](https://textbook.cs168.io/routing/link-state.html), [Addressing](https://textbook.cs168.io/routing/addressing.html)<br>[Routers](https://textbook.cs168.io/routing/router.html) |
| P8 | Lab 7: Putting it together | 21-22. Datacenters: Topology, Routing | [Topology](https://textbook.cs168.io/datacenter/topology.html), [Congestion](https://textbook.cs168.io/datacenter/datacenter-cc.html)<br>[Routing](https://textbook.cs168.io/datacenter/datacenter-routing.html), [Addressing](https://textbook.cs168.io/datacenter/datacenter-addressing.html), [Virtualization](https://textbook.cs168.io/datacenter/virtualization.html) |
| P9 | 无 Lab | 9-10. Routing (BGP)<br>16-17. Applications (DNS, HTTP)<br>23. SDN<br>24-25. Multicast | [Model](https://textbook.cs168.io/routing/autonomous-systems.html), [Design](https://textbook.cs168.io/routing/bgp.html), [Implementation](https://textbook.cs168.io/routing/bgp-implementation.html), [IP Header](https://textbook.cs168.io/routing/ip-header.html)<br>[DNS](https://textbook.cs168.io/applications/dns.html), [HTTP](https://textbook.cs168.io/applications/http.html)<br>[SDN](https://textbook.cs168.io/datacenter/sdn.html), [Host Networking](https://textbook.cs168.io/special-topics/host-networking.html)<br>[Multicast](https://textbook.cs168.io/beyond-client-server/), [Operations](https://textbook.cs168.io/beyond-client-server/collective-operations.html), [Implementation](https://textbook.cs168.io/beyond-client-server/collective-implementations.html) |
| P10 | 无 Lab | 26. Wireless<br>27. Cellular | [Wireless](https://textbook.cs168.io/special-topics/wireless.html)<br>[Cellular](https://textbook.cs168.io/special-topics/cellular.html) |

感谢 Stanford CS144 和 Berkeley CS168 开源的顶级课程资源。
