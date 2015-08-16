import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

	static class VertexComparator implements Comparator<Vertex> {

		@Override
		public int compare(Vertex v0, Vertex v1) {
			if (v0.dist < v1.dist) {
				return -1;
			}
			return 1;
		}

	}

	static class Vertex {
		int j2, j3;
		int dist;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		while (t > 0) {

			String[] in = br.readLine().split(" ");

			int a = Integer.parseInt(in[0]);
			int b = Integer.parseInt(in[1]);
			int c = Integer.parseInt(in[2]);
			int d = Integer.parseInt(in[3]);

			Comparator<Vertex> comp = new VertexComparator();
			PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>(10000,comp);
			int[][] dist = new int[c + 1][c + 1];

			for (int i = 0; i < c + 1; i++)
				Arrays.fill(dist[i], 1000000);
			boolean[][] vis = new boolean[c + 1][c + 1];
			Vertex src = new Vertex();
			dist[0][c] = 0;
			src.j2 = 0;
			src.dist = 0;
			src.j3 = c;
			pq.add(src);
			int ansDist = 1000000;
			int ansD = -1;
			while (!pq.isEmpty()) {
				Vertex curr = pq.poll();
				if (!vis[curr.j2][curr.j3]) {
				

					vis[curr.j2][curr.j3] = true;
					if (curr.j2 == d || curr.j3 == d
							|| c - (curr.j2 + curr.j3) == d) {

						if (ansD==d && ansDist > dist[curr.j2][curr.j3] ) {
							ansDist = dist[curr.j2][curr.j3];
						}else if(ansD!=d){
							ansDist = dist[curr.j2][curr.j3];

						}
							ansD = d;
						
					} else if (ansD != d) {
						if (curr.j2 < d && curr.j2 >= ansD) {
							if (curr.j2 == ansD) {
								ansDist = Math.min(dist[curr.j2][curr.j3],
										ansDist);
							} else {
								ansDist = dist[curr.j2][curr.j3];
								ansD = curr.j2;
							}
						}
						if (c - (curr.j2 + curr.j3) < d
								&& c - (curr.j2 + curr.j3) >= ansD) {
							if (c - (curr.j2 + curr.j3) == ansD) {
								ansDist = Math.min(dist[curr.j2][curr.j3],
										ansDist);
							} else {
								ansDist = dist[curr.j2][curr.j3];
								ansD = c - (curr.j2 + curr.j3);

							}
						}
						if (curr.j3 < d && curr.j3 >= ansD) {
							if (curr.j3 == ansD) {
								ansDist = Math.min(dist[curr.j2][curr.j3],
										ansDist);
							} else {
								ansDist = dist[curr.j2][curr.j3];
								ansD = curr.j3;
							}
						}
					}

					/* Six Neighbouring Vertices */
					Vertex adj = new Vertex();
					adj.j2 = Math.min(b, c - (curr.j2 + curr.j3) + curr.j2);
					adj.j3 = curr.j3;
					if (dist[curr.j2][curr.j3] + (adj.j2 - curr.j2) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (adj.j2 - curr.j2);
						pq.add(adj);
					}

					adj = new Vertex();
					adj.j3 = Math.min(c, c - (curr.j2 + curr.j3) + curr.j3);
					adj.j2 = curr.j2;
					if (dist[curr.j2][curr.j3] + (adj.j3 - curr.j2) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (adj.j3 - curr.j3);
						pq.add(adj);
					}

					adj = new Vertex();

					adj.j2 = Math.max(0, curr.j2
							- (a - (c - (curr.j2 + curr.j3))));
					adj.j3 = curr.j3;
					if (dist[curr.j2][curr.j3] + (curr.j2 - adj.j2) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (curr.j2 - adj.j2);
						pq.add(adj);
					}

					adj = new Vertex();
					adj.j3 = Math.min(c, curr.j2 + curr.j3);
					adj.j2 = curr.j2 - (adj.j3 - curr.j3);

					if (dist[curr.j2][curr.j3] + (adj.j3 - curr.j3) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (adj.j3 - curr.j3);
						pq.add(adj);
					}

					adj = new Vertex();
					adj.j3 = Math.max(0,curr.j3
							- (a - (c - (curr.j2 + curr.j3))));
					adj.j2 = curr.j2;
					if (dist[curr.j2][curr.j3] + (curr.j3 - adj.j3) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (curr.j3 - adj.j3);
						pq.add(adj);
					}

					adj = new Vertex();
					adj.j2 = Math.min(b, curr.j3 + curr.j2);
					adj.j3 = curr.j3 - (adj.j2 - curr.j2);
					if (dist[curr.j2][curr.j3] + (adj.j2 - curr.j2) <= dist[adj.j2][adj.j3]) {
						adj.dist = dist[adj.j2][adj.j3] = dist[curr.j2][curr.j3]
								+ (adj.j2 - curr.j2);
						pq.add(adj);
					}
				}

			}
			System.out.println(ansDist + " " + ansD);
			t--;
			
		}

	}

}
