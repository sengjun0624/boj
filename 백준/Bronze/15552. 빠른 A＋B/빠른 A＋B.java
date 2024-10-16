
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String cmd = bf.readLine();
		int t = Integer.parseInt(cmd);

		for (int i = 0; i < t; i++) {
			cmd = bf.readLine();
			StringTokenizer st = new StringTokenizer(cmd);
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			bw.write(a + b + "\n");

		}
		bw.flush();
		bw.close();

	}
}
